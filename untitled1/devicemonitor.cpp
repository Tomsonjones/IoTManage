#include "devicemonitor.h"
#include "ui_devicemonitor.h"

DeviceMonitor::DeviceMonitor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceMonitor)
{
    ui->setupUi(this);

    //stackedWidget 里默认有两个页面 给他删了先

    // 从 stackedWidget 中删除特定的页面
    QWidget* page1 = ui->stackedWidget->widget(0); // 获取第一个页面
    ui->stackedWidget->removeWidget(page1);        // 删除第一个页面
    delete page1;                                  // 删除该页面对象

    QWidget* page2 = ui->stackedWidget->widget(0); // 获取第2个页面
    ui->stackedWidget->removeWidget(page2);        // 删除第2个页面
    delete page2;

    m_pDataMonitor = new DataMonitor ;
    m_pEquipmentPanel = new EquipmentPanel ;
    m_pBarChart = new BarChart ;
    m_pLineGraph = new LineGraph ;

    ui->stackedWidget->addWidget(m_pDataMonitor);
    ui->stackedWidget->addWidget(m_pEquipmentPanel);
    ui->stackedWidget->addWidget(m_pBarChart);
    ui->stackedWidget->addWidget(m_pLineGraph);

    // 默认显示第一个页面
    ui->stackedWidget->setCurrentIndex(0);


    // 为设备监控按钮连接信号槽
    connect(ui->pushButton_DataMonitor, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(0);  // 切换到设备监控界面
    });

    // 为数据查询按钮连接信号槽
    connect(ui->pushButton_EquipmentPanel, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(1);  // 切换到数据查询界面
    });

    // 为系统设置按钮连接信号槽
    connect(ui->pushButton_BarChart, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(2);  // 切换到系统设置界面
    });

    // 为其他设置按钮连接信号槽
    connect(ui->pushButton_LineGraph, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(3);  // 切换到其他设置界面
    });

}

DeviceMonitor::~DeviceMonitor()
{
    delete ui;
}
