#include "othersettings.h"
#include "ui_othersettings.h"
#include "usermanagementlow.h"
UserManagementLow *m_pUserManagementLow;

OtherSettings::OtherSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OtherSettings)
{
    ui->setupUi(this);

    // 从 stackedWidget 中删除特定的页面
    QWidget* page1 = ui->stackedWidget->widget(0); // 获取第一个页面
    ui->stackedWidget->removeWidget(page1);        // 删除第一个页面
    delete page1;                                  // 删除该页面对象

    QWidget* page2 = ui->stackedWidget->widget(0); // 获取第2个页面
    ui->stackedWidget->removeWidget(page2);        // 删除第2个页面
    delete page2;

    // 创建 UserManagement 和 UserManagementLow
    m_pUserManagement = new UserManagement;
    m_pUserManagementLow = new UserManagementLow;

    // 管理员显示高级用户管理界面
    ui->stackedWidget->addWidget(m_pUserManagement);
    // 普通用户显示低权限管理界面
    ui->stackedWidget->addWidget(m_pUserManagementLow);

    // 界面跳转信号槽连接
    connect(ui->pushButton_UserManagement, &QPushButton::clicked, this, [=]() {
        if (CurrentRole == "admin") {
            ui->stackedWidget->setCurrentIndex(0);  // 跳转到管理员界面
        } else if (CurrentRole == "user") {
            ui->stackedWidget->setCurrentIndex(1);  // 跳转到普通用户界面
        }
    });
}

OtherSettings::~OtherSettings()
{
    delete ui;
}

void OtherSettings::UserManagementDisplay()
{
    if (CurrentRole == "admin") {
        ui->stackedWidget->setCurrentIndex(0);  // 跳转到管理员界面
    } else if (CurrentRole == "user") {
        ui->stackedWidget->setCurrentIndex(1);  // 跳转到普通用户界面
    }
}
