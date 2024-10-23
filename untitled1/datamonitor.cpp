#include "datamonitor.h"
#include "ui_datamonitor.h"
#include "filterdialog.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QTimer>
#include <QLabel>
#include <cstdlib>
#include <ctime>

DataMonitor::DataMonitor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataMonitor),
    dataUpdateTimer(new QTimer(this))  // 初始化定时器
{
    ui->setupUi(this);

    // 初始化随机数生成器，只需调用一次
    srand(time(0));

    // 确保数据库连接只创建一次
    if (!QSqlDatabase::contains("qt_sql_default_connection")) {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("D:/code/qt/IoTManage/build-untitled1-Desktop_Qt_5_14_2_MinGW_64_bit-Debug/users.db");
        if (!db.open()) {
            qDebug() << "Error: Could not connect to database.";
            return;
        }
    }

    // 初始化模型并设置表格
    model = new QSqlTableModel(this);
    model->setTable("devices");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    // 设置tableview的每列标题
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("设备名称"));
    model->setHeaderData(2, Qt::Horizontal, tr("类型"));
    model->setHeaderData(3, Qt::Horizontal, tr("位置"));
    model->setHeaderData(4, Qt::Horizontal, tr("实时数据"));
    model->setHeaderData(5, Qt::Horizontal, tr("单位"));
    model->setHeaderData(6, Qt::Horizontal, tr("状态"));

    // 设置表格视图
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableView->setColumnWidth(0, 40);
    ui->tableView->setColumnWidth(1, 150);
    ui->tableView->setColumnWidth(2, 100);
    ui->tableView->setColumnWidth(3, 160);
    ui->tableView->setColumnWidth(4, 100);
    ui->tableView->setColumnWidth(5, 100);
    ui->tableView->setColumnWidth(6, 150);

    // 创建异常提示框
    // 创建一个qlabel
    alertLabel = new QLabel(this);
    // 设置文本居中
    alertLabel->setAlignment(Qt::AlignCenter);
    //锁定宽度
    alertLabel->setMinimumWidth(80);
    alertLabel->setMaximumWidth(80);
    //和旁边的tableview高度设置一样
    alertLabel->setMinimumHeight(ui->tableView->height());

    // 水平布局qlabel 和 qtableview
    QVBoxLayout *alertLayout = new QVBoxLayout();
    alertLayout->addWidget(alertLabel);
    //垂直居中
    alertLayout->addStretch();

    // 竖直布局
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(ui->tableView);
    mainLayout->addLayout(alertLayout);
    setLayout(mainLayout);

    // 启动定时器，每10秒更新一次数据
    connect(dataUpdateTimer, &QTimer::timeout, this, &DataMonitor::updateData);
    connect(dataUpdateTimer, &QTimer::timeout, this, &DataMonitor::checkForAlerts);
    connect(dataUpdateTimer, &QTimer::timeout, this, &DataMonitor::insertDataToDatabase);
    dataUpdateTimer->start(10000);  // 每10秒触发一次

    // 在界面初始化的时候先刷新一次数据（后三列）
    updateData();
    checkForAlerts();
}

DataMonitor::~DataMonitor()
{
    delete ui;
}

void DataMonitor::updateData()
{
    // 每10秒先从数据库里重新读一下看看有没有新设备
    model->select();

    for (int row = 0; row < model->rowCount(); ++row) {
        QString deviceName = model->index(row, 1).data().toString();
        int randomValue = 0;

        // 根据设备名称生成不同范围的随机数
        if (deviceName == "测温仪") {
            randomValue = rand() % 41;  // 生成0-40的随机数
            model->setData(model->index(row, 5), "摄氏度");
        } else if (deviceName == "湿度计") {
            randomValue = rand() % 101;  // 0-100
            model->setData(model->index(row, 5), "%");
        } else if (deviceName == "光照检测仪") {
            randomValue = rand() % 1001;  // 0-1000
            model->setData(model->index(row, 5), "lux");
        }

        // 插入实时数据
        model->setData(model->index(row, 4), randomValue);

        // 更新状态列
        QString status;
        if (deviceName == "测温仪") {
            if (randomValue >= 8 && randomValue <= 30) {
                status = "正常";
            } else if (randomValue < 8) {
                status = "过低";
            } else {
                status = "过高";
            }
        } else if (deviceName == "湿度计") {
            if (randomValue >= 25 && randomValue <= 75) {
                status = "正常";
            } else if (randomValue < 25) {
                status = "过低";
            } else {
                status = "过高";
            }
        } else if (deviceName == "光照检测仪") {
            if (randomValue >= 100 && randomValue <= 900) {
                status = "正常";
            } else if (randomValue < 100) {
                status = "过低";
            } else {
                status = "过高";
            }
        }
        // 在第六行重新插入数据覆盖原数据
        model->setData(model->index(row, 6), status);  // 更新状态列
    }
}

void DataMonitor::checkForAlerts()
{
    bool hasAlert = false;

    // 遍历所有行，检查是否有过高或过低状态
    for (int row = 0; row < model->rowCount(); ++row) {
        QString status = model->index(row, 6).data().toString();
        if (status == "过高" || status == "过低") {
            hasAlert = true;
            break;
        }
    }

    // 只要任意一个设备有异常则在右侧label显示
    if (hasAlert) {
        alertLabel->setStyleSheet("QLabel { color : black; font-weight: bold; background-color : red; }");
        alertLabel->setText("异常");
    } else {
        // 设置label字体和背景色
        alertLabel->setStyleSheet("QLabel { color : black; font-weight: bold; background-color : green; }");
        alertLabel->setText("正常");
    }
}

#include <QDateTime>

void DataMonitor::insertDataToDatabase()
{
    QSqlQuery query;

    //遍历所有行
    for (int row = 0; row < model->rowCount(); ++row) {
        //取出第一列 （设备id）
        QString deviceName = model->index(row, 1).data().toString();
        int deviceID = model->index(row, 0).data().toInt();  //
        //第四列 （实时数据）
        int realTimeData = model->index(row, 4).data().toInt();
        // 当前时间
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

        // 根据设备名称 决定数据插入到哪个字段
        // 如果是温度 将实时数据插入到温度 湿度和光照插入空字符串
        QString temperature, humidity, light;

        if (deviceName == "测温仪") {
            temperature = QString::number(realTimeData);
            humidity = "";
            light = "";
        } else if (deviceName == "湿度计") {
            humidity = QString::number(realTimeData);
            temperature = "";
            light = "";
        } else if (deviceName == "光照检测仪") {
            light = QString::number(realTimeData);
            temperature = "";
            humidity = "";
        }

        // 构建SQL插入语句
        query.prepare("INSERT INTO data (device_id, timestamp, temperature, humidity, light) "
                      "VALUES (:device_id, :timestamp, :temperature, :humidity, :light)");
        //把:device_id  :timestamp   :temperature  :humidity :light 替换成正确的数值
        query.bindValue(":device_id", deviceID);
        query.bindValue(":timestamp", currentTime);
        query.bindValue(":temperature", temperature);
        query.bindValue(":humidity", humidity);
        query.bindValue(":light", light);

        //执行插入sql语句
        if (!query.exec()) {
            //qDebug() << "插入失败" << query.lastError();
        } else {
            //qDebug() << "数据插入成功";
        }
    }
}

