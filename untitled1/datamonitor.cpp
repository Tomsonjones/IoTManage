#include "datamonitor.h"
#include "ui_datamonitor.h"

DataMonitor::DataMonitor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataMonitor)
{
    ui->setupUi(this);
}

DataMonitor::~DataMonitor()
{
    delete ui;
}
