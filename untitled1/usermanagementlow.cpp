#include "usermanagementlow.h"
#include "ui_usermanagementlow.h"
#include "readonlydelegate.h"

UserManagementLow::UserManagementLow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserManagementLow)
{
    ui->setupUi(this);

    ui->tableView->setStyleSheet(
        "QHeaderView::section {"
        "    font-size: 12px;"  // 修改为你想要的字体大小
        "    padding: 4px;"
        "    background-color: #f0f0f0;"
        "    border: 1px solid #d4d4d4;"
        "}"
    );

    // 创建按钮
    ChangeButton = new QPushButton(tr("修改"));
    ChangeButton->setFixedSize(100, 48);

    buttonBox = new QDialogButtonBox(Qt::Vertical);
    buttonBox->addButton(ChangeButton, QDialogButtonBox::ActionRole);

    // 连接修改按钮的信号与槽
    connect(ChangeButton, &QAbstractButton::clicked, this, &UserManagementLow::ChangeAction);

    // 创建主布局
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(ui->tableView);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    // 设置窗口尺寸和标题
    setMinimumSize(600, 400);
    setWindowTitle(tr("User Management"));
}

void UserManagementLow::loadUserData(const QString& username) {
    // 检查 CurrentUsername 是否为空
    if (username.isEmpty()) {
        qDebug() << "用户名为空，无法加载数据";
        return;
    }

    // 创建一个新的数据库连接，并指定使用 SQLite 数据库引擎
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/code/qt/IoTManage/build-untitled1-Desktop_Qt_5_14_2_MinGW_64_bit-Debug/users.db");
    if (!db.open()) {
        qDebug() << "Error: Could not connect to database.";
        return;
    }

    // 初始化模型并设置表格，只展示当前用户的数据
    model = new QSqlTableModel(this);
    model->setTable("users");
    model->setFilter(QString("username = '%1'").arg(username));  // 过滤只显示当前用户
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    // 设置表头
    model->setHeaderData(0, Qt::Horizontal, tr("用户ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("用户名"));
    model->setHeaderData(2, Qt::Horizontal, tr("密码"));
    model->setHeaderData(3, Qt::Horizontal, tr("邮箱"));
    model->setHeaderData(4, Qt::Horizontal, tr("电话"));
    model->setHeaderData(5, Qt::Horizontal, tr("昵称"));
    model->setHeaderData(6, Qt::Horizontal, tr("权限"));

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

    // 遍历模型中的所有行，修改 role 列的显示值
    for (int row = 0; row < model->rowCount(); ++row) {
        //取出model第六列的数据
        QModelIndex index = model->index(row, 6);
        QString role = model->data(index).toString();
        //根据数据不同更改显示内容
        if (role == "admin") {
            model->setData(index, "管理员");
        } else if (role == "user") {
            model->setData(index, "用户");
        }
    }
}

void UserManagementLow::ChangeAction() {
    // 提交修改，不能修改用户名
    if (!model->submitAll()) {
        QMessageBox::critical(this, tr("修改失败"), tr("修改失败: ") + model->lastError().text());
    } else {
        QMessageBox::information(this, tr("修改成功"), tr("用户信息已成功修改。"));
    }
}

UserManagementLow::~UserManagementLow() {
    delete ui;
}
