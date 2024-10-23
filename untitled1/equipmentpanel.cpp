#include "equipmentpanel.h"
#include "ui_equipmentpanel.h"
#include "adddevice.h"
#include "filterdialog.h"

EquipmentPanel::EquipmentPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EquipmentPanel)
{
    ui->setupUi(this);
    // 确保数据库连接只创建一次
    //QSqlDatabase::contains("qt_sql_default_connection")  用于检测是否存在数据库连接
    //如果存在直接使用 不存在才会建立新的连接
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

    // 设置表头，显示所有列
    //设备名称、类型、位置、制造商、型号、安装日期
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("设备名称"));
    model->setHeaderData(2, Qt::Horizontal, tr("类型"));
    model->setHeaderData(3, Qt::Horizontal, tr("位置"));
    model->setHeaderData(4, Qt::Horizontal, tr("制造商"));
    model->setHeaderData(5, Qt::Horizontal, tr("型号"));
    model->setHeaderData(6, Qt::Horizontal, tr("安装日期"));

    // 设置表格视图
    ui->tableView->setModel(model);

    // 设置每一列的固定宽度
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableView->setColumnWidth(0, 40);
    ui->tableView->setColumnWidth(1, 150);
    ui->tableView->setColumnWidth(2, 100);
    ui->tableView->setColumnWidth(3, 160);
    ui->tableView->setColumnWidth(4, 100);
    ui->tableView->setColumnWidth(5, 100);
    ui->tableView->setColumnWidth(6, 150);

    // 创建按钮
    AddButton = new QPushButton(tr("添加"));
    DeleteButton = new QPushButton(tr("删除"));
    filterButton = new QPushButton(tr("筛选"));

    AddButton->setFixedSize(75, 45);
    DeleteButton->setFixedSize(75, 45);
    filterButton->setFixedSize(75, 45);

    buttonBox = new QDialogButtonBox(Qt::Vertical);
    buttonBox->addButton(AddButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(DeleteButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(filterButton, QDialogButtonBox::ActionRole);

    // 连接按钮的信号与槽
    connect(DeleteButton, &QAbstractButton::clicked, this, &EquipmentPanel::DeleteAction);
    connect(AddButton, &QAbstractButton::clicked, this, &EquipmentPanel::AddAction);
    connect(filterButton, &QAbstractButton::clicked, this, &EquipmentPanel::FilterAction);

    // 创建主布局
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(ui->tableView);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);
}

void EquipmentPanel::FilterAction()
{
    // 创建并显示筛选对话框
    FilterDialog dialog(this);
    //用模态方式打开新的dialog弹窗
    if (dialog.exec() == QDialog::Accepted) {
        // 获取用户选择的设备名称和位置
        QString deviceName = dialog.getDeviceName();
        QString location = dialog.getLocation();

        QString filter;

        // 拼接筛选字符串
        // 筛选设备名
        if (!deviceName.isEmpty()) {
            filter += QString("name = '%1'").arg(deviceName);
        }

        //筛选位置
        if (!location.isEmpty()) {
            if (!filter.isEmpty()) {
                filter += " AND ";
            }
            filter += QString("location = '%1'").arg(location);
        }

        // 应用筛选条件到模型
        //最终字符串类似于 “  name ='湿度计' AND location = '位置1'  ”
        //setfilter 会将拼接好的字符串到数据库中执行筛选
        model->setFilter(filter);
        //重新加载模型 只加载符合筛选条件的
        //如果要看所有设备 筛选两个空就可以

        //要添加其他属性筛选条件 可以继续拼接字符串
        model->select();
    }
}

void EquipmentPanel::DeleteAction() {
    // 获取选中的模型行并删除
    QItemSelectionModel *selectionModel = ui->tableView->selectionModel();
    if (!selectionModel) {
        QMessageBox::warning(this, tr("删除失败"), tr("无法选择要删除的记录"));
        return;
    }

    QModelIndexList selectedIndexes = selectionModel->selectedRows();
    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, tr("删除失败"), tr("请先选择要删除的记录"));
        return;
    }

    // 显示确认对话框
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("确认删除"), tr("确定要删除选中的记录吗"),
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No) {
        return; // 用户取消删除操作
    }

    // 获取选中行并删除
    QModelIndex index = selectedIndexes.first();
    int row = index.row();
    model->removeRow(row);

    // 提交删除操作
    if (model->submitAll()) {
        QMessageBox::information(this, tr("删除成功"), tr("记录已成功删除。"));
        // 重新加载表格数据以更新视图
        model->select();  // 这里添加重新加载
    } else {
        QMessageBox::critical(this, tr("删除失败"), tr("无法删除记录: ") + model->lastError().text());
    }
}


void EquipmentPanel::AddAction()
{
    AddDevice dialog(this);

    // 通过 exec() 打开对话框，并等待用户点击确定或取消
    if (dialog.exec() == QDialog::Accepted) {
        model->select();  // 这里添加重新加载
    } else {

    }
}


EquipmentPanel::~EquipmentPanel()
{
    delete ui;
}
