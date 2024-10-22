#include "devicemonitorbutton.h"
#include "ui_devicemonitorbutton.h"

DeviceMonitorButton::DeviceMonitorButton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceMonitorButton)
{
    ui->setupUi(this);
}

DeviceMonitorButton::~DeviceMonitorButton()
{
    delete ui;
}
