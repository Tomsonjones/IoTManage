#include "normalsettings.h"
#include "ui_normalsettings.h"

NormalSettings::NormalSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NormalSettings)
{
    ui->setupUi(this);
}

NormalSettings::~NormalSettings()
{
    delete ui;
}
