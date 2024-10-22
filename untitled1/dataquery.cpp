#include "dataquery.h"
#include "ui_dataquery.h"

DataQuery::DataQuery(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataQuery)
{
    ui->setupUi(this);
    // 从 stackedWidget 中删除特定的页面
    QWidget* page1 = ui->stackedWidget->widget(0); // 获取第一个页面
    ui->stackedWidget->removeWidget(page1);        // 删除第一个页面
    delete page1;                                  // 删除该页面对象

    QWidget* page2 = ui->stackedWidget->widget(0); // 获取第2个页面
    ui->stackedWidget->removeWidget(page2);        // 删除第2个页面
    delete page2;


    m_pAlarmRecord = new AlarmRecord ;
    m_pOperationRecords = new OperationRecords ;
    m_pOperationRecord = new OperationRecord ;

    ui->stackedWidget->addWidget(m_pAlarmRecord);
    ui->stackedWidget->addWidget(m_pOperationRecords);
    ui->stackedWidget->addWidget(m_pOperationRecord);

    // 默认显示第一个页面
    ui->stackedWidget->setCurrentIndex(0);


    //界面跳转信号槽连接
    connect(ui->pushButton_AlarmRecord, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(0);
    });

    //界面跳转信号槽连接
    connect(ui->pushButton_OperationRecords, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(1);
    });

    //界面跳转信号槽连接
    connect(ui->pushButton_OperationRecord, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(2);
    });



}

DataQuery::~DataQuery()
{
    delete ui;
}
