#include "othersettingsbutton.h"
#include "ui_othersettingsbutton.h"

OtherSettingsButton::OtherSettingsButton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OtherSettingsButton)
{
    ui->setupUi(this);
}

OtherSettingsButton::~OtherSettingsButton()
{
    delete ui;
}
