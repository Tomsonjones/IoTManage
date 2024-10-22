#include "equipmentpanel.h"
#include "ui_equipmentpanel.h"

EquipmentPanel::EquipmentPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EquipmentPanel)
{
    ui->setupUi(this);
}

EquipmentPanel::~EquipmentPanel()
{
    delete ui;
}
