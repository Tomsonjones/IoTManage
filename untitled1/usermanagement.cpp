#include "usermanagement.h"
#include "ui_usermanagement.h"

UserManagement::UserManagement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserManagement)
{
    ui->setupUi(this);

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
        model->setTable("users");
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model->select();

        // 设置表头，显示所有列
        model->setHeaderData(0, Qt::Horizontal, tr("用户ID"));
        model->setHeaderData(1, Qt::Horizontal, tr("账户"));
        model->setHeaderData(2, Qt::Horizontal, tr("密码"));
        model->setHeaderData(3, Qt::Horizontal, tr("邮箱"));
        model->setHeaderData(4, Qt::Horizontal, tr("电话"));
        model->setHeaderData(5, Qt::Horizontal, tr("昵称"));
        model->setHeaderData(6, Qt::Horizontal, tr("角色"));

        // 设置表格视图
        ui->tableView->setModel(model);

        // 设置每一列的固定宽度
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
        ui->tableView->setColumnWidth(0, 80);
        ui->tableView->setColumnWidth(1, 100);
        ui->tableView->setColumnWidth(2, 100);
        ui->tableView->setColumnWidth(3, 160);
        ui->tableView->setColumnWidth(4, 100);
        ui->tableView->setColumnWidth(5, 100);
        ui->tableView->setColumnWidth(6, 50);

        // 创建按钮
        DeleteButton = new QPushButton(tr("删除"));
        ChangeButton = new QPushButton(tr("修改"));
        ChangeButton->setFixedSize(100, 48);
        DeleteButton->setFixedSize(100, 48);

        buttonBox = new QDialogButtonBox(Qt::Vertical);
        buttonBox->addButton(DeleteButton, QDialogButtonBox::ActionRole);
        buttonBox->addButton(ChangeButton, QDialogButtonBox::ActionRole);

        // 连接按钮的信号与槽
        connect(DeleteButton, &QAbstractButton::clicked, this, &UserManagement::DeleteAction);
        connect(ChangeButton, &QAbstractButton::clicked, this, &UserManagement::ChangeAction);

        // 创建主布局
        QHBoxLayout *mainLayout = new QHBoxLayout;
        mainLayout->addWidget(ui->tableView);
        mainLayout->addWidget(buttonBox);
        setLayout(mainLayout);

        // 设置窗口尺寸和标题
        setMinimumSize(600, 400);
        setWindowTitle(tr("User Management"));
    }

void UserManagement::DeleteAction() {
    // 获取选中的模型行并删除
    QItemSelectionModel *selectionModel = ui->tableView->selectionModel();
    if (!selectionModel) {
        QMessageBox::warning(this, tr("删除失败"), tr("无法选择要删除的记录。"));
        return;
    }

    QModelIndexList selectedIndexes = selectionModel->selectedRows();
    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, tr("删除失败"), tr("请先选择要删除的记录。"));
        return;
    }

    // 显示确认对话框
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("确认删除"), tr("确定要删除选中的记录吗？"),
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
    } else {
        QMessageBox::critical(this, tr("删除失败"), tr("无法删除记录: ") + model->lastError().text());
    }
}

void UserManagement::ChangeAction() {
    // 提交修改
    if (model->submitAll()) {
        QMessageBox::information(this, tr("修改成功"), tr("用户信息已成功修改。"));
    } else {
        QMessageBox::critical(this, tr("修改失败"), tr("修改失败: ") + model->lastError().text());
    }
}

UserManagement::~UserManagement() {
    delete ui;
}
