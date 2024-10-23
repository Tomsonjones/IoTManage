#include "adddevice.h"
#include "ui_adddevice.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QDebug>
#include "mysqlite.h"

AddDevice::AddDevice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDevice)
{
    ui->setupUi(this);

    //去除右上角的功能按钮 并添加标题
    setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
    setWindowTitle("添加设备");

    // 创建ComboBox 组件
    deviceNameComboBox = new QComboBox(this);
    deviceNameComboBox->addItems({"测温仪", "湿度计", "光照检测仪"});

    typeComboBox = new QComboBox(this);
    typeComboBox->addItems({"通用类型1", "通用类型2"});

    locationComboBox = new QComboBox(this);
    locationComboBox->addItems({"位置1", "位置2", "位置3"});

    manufacturerComboBox = new QComboBox(this);
    manufacturerComboBox->addItems({"制造商A", "制造商B", "制造商C"});

    modelComboBox = new QComboBox(this);
    modelComboBox->addItems({"型号X1", "型号X2"});

    // 使用 QDateEdit 来作为安装日期选择组件
    installDateEdit = new QDateEdit(this);
    installDateEdit->setCalendarPopup(true); // 启用日历弹出窗口

    // 创建确认和取消按钮
    confirmButton = new QPushButton("确认", this);
    cancelButton = new QPushButton("取消", this);

    // 将布局添加到对话框
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // 添加设备名称、类型、位置、厂商、型号、安装日期到布局
    mainLayout->addWidget(new QLabel("名称:", this));
    mainLayout->addWidget(deviceNameComboBox);

    mainLayout->addWidget(new QLabel("类型:", this));
    mainLayout->addWidget(typeComboBox);

    mainLayout->addWidget(new QLabel("位置:", this));
    mainLayout->addWidget(locationComboBox);

    mainLayout->addWidget(new QLabel("厂商:", this));
    mainLayout->addWidget(manufacturerComboBox);

    mainLayout->addWidget(new QLabel("型号:", this));
    mainLayout->addWidget(modelComboBox);

    mainLayout->addWidget(new QLabel("安装日期:", this));
    mainLayout->addWidget(installDateEdit);

    // 添加按钮到布局
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(confirmButton);
    buttonLayout->addWidget(cancelButton);

    mainLayout->addLayout(buttonLayout);

    // 设置主布局
    setLayout(mainLayout);
    //绑定添加设备按钮和取消按钮信号槽
    connect(confirmButton, &QPushButton::clicked, this, &AddDevice::onConfirmButtonClicked);
    connect(cancelButton, &QPushButton::clicked, this, &AddDevice::onCancelButtonClicked);
}

void AddDevice::onConfirmButtonClicked()
{
    // 获取每个ComboBox的文本
    QString deviceName = deviceNameComboBox->currentText();
    QString type = typeComboBox->currentText();
    QString location = locationComboBox->currentText();
    QString manufacturer = manufacturerComboBox->currentText();
    QString model = modelComboBox->currentText();

    // 获取安装日期的文本
    QString installDate = installDateEdit->date().toString("yyyy-MM-dd");

    // 打印输出 (你可以在这里进行其他处理)
    qDebug() << "设备名称: " << deviceName;
    qDebug() << "类型: " << type;
    qDebug() << "位置: " << location;
    qDebug() << "厂商: " << manufacturer;
    qDebug() << "型号: " << model;
    qDebug() << "安装日期: " << installDate;


    MySqlite mysql3;
    mysql3.AddDevice(deviceName,type,location,manufacturer,model,installDate);
    // 关闭窗口
    this->accept();
}

void AddDevice::onCancelButtonClicked()
{
    // 直接关闭窗口
    this->reject();
}

AddDevice::~AddDevice()
{
    delete ui;
}
