#include "systemsettings.h"
#include "ui_systemsettings.h"

SystemSettings::SystemSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SystemSettings)
{
    ui->setupUi(this);

    // 从 stackedWidget 中删除特定的页面
    QWidget* page1 = ui->stackedWidget->widget(0); // 获取第一个页面
    ui->stackedWidget->removeWidget(page1);        // 删除第一个页面
    delete page1;                                  // 删除该页面对象

    QWidget* page2 = ui->stackedWidget->widget(0); // 获取第2个页面
    ui->stackedWidget->removeWidget(page2);        // 删除第2个页面
    delete page2;

    m_pNormalSettings = new NormalSettings ;
    m_pEquipManage = new EquipManage ;

    ui->stackedWidget->addWidget(m_pNormalSettings);
    ui->stackedWidget->addWidget(m_pEquipManage);

    // 默认显示第一个页面
    ui->stackedWidget->setCurrentIndex(0);


    //界面跳转信号槽连接
    connect(ui->pushButton_NormalSettings, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(0);
    });

    //界面跳转信号槽连接
    connect(ui->pushButton_EquipManage, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(1);
    });

}

SystemSettings::~SystemSettings()
{
    delete ui;
}
