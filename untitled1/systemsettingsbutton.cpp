#include "systemsettingsbutton.h"
#include "ui_systemsettingsbutton.h"

SystemSettingsButton::SystemSettingsButton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SystemSettingsButton)
{
    ui->setupUi(this);
}

SystemSettingsButton::~SystemSettingsButton()
{
    delete ui;
}
