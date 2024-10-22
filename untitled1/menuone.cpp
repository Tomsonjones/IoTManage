#include "menuone.h"
#include "ui_menuone.h"

#include <QtWidgets>
#include <QtSql>
#include "mylogin.h"

MenuOne::MenuOne(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuOne)
{
    ui->setupUi(this);

    // 初始化页面
    m_pDeviceMonitor = new DeviceMonitor ;
    m_pDataQuery = new DataQuery ;
    m_pSystemSettings = new SystemSettings ;
    m_pOtherSettings = new OtherSettings ;

    connect(ui->otherSettingsButton,&QAbstractButton::clicked,m_pOtherSettings,&OtherSettings::UserManagementDisplay);

    //stackedWidget 里默认有两个页面 给他删了先

    // 从 stackedWidget 中删除特定的页面
    QWidget* page1 = ui->stackedWidget->widget(0); // 获取第一个页面
    ui->stackedWidget->removeWidget(page1);        // 删除第一个页面
    delete page1;                                  // 删除该页面对象

    QWidget* page2 = ui->stackedWidget->widget(0); // 获取第2个页面
    ui->stackedWidget->removeWidget(page2);        // 删除第2个页面
    delete page2;                                  // 删除该页面对象

    // 将每个页面按顺序添加到 QStackedWidget
    ui->stackedWidget->addWidget(m_pDeviceMonitor);     // Index 0
    ui->stackedWidget->addWidget(m_pDataQuery);         // Index 1
    ui->stackedWidget->addWidget(m_pSystemSettings);    // Index 2
    ui->stackedWidget->addWidget(m_pOtherSettings);     // Index 3

    // 设置窗口标题
    setWindowTitle(tr("IoT Manage"));

    // 设置 QuitButton 的样式
    ui->QuitButton->setStyleSheet("background-color: rgb(17, 48, 76);");

    // 连接退出按钮
    connect(ui->QuitButton, &QPushButton::clicked, this, &MenuOne::QuitBtn);
    connect(ui->QuitButton, &QPushButton::clicked, this, &MenuOne::ChangeInterfaceSize);

    // 默认显示第一个页面
    ui->stackedWidget->setCurrentIndex(0);


    // 为设备监控按钮连接信号槽
    connect(ui->deviceMonitorButton, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(0);  // 切换到设备监控界面
    });

    // 为数据查询按钮连接信号槽
    connect(ui->dataQueryButton, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(1);  // 切换到数据查询界面
    });

    // 为系统设置按钮连接信号槽
    connect(ui->systemSettingsButton, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(2);  // 切换到系统设置界面
    });

    // 为其他设置按钮连接信号槽
    connect(ui->otherSettingsButton, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(3);  // 切换到其他设置界面
    });
}

void MenuOne::QuitBtn(){
    display(0);
}

MenuOne::~MenuOne()
{
    delete ui;
}



