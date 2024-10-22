#include "equipmanage.h"
#include "ui_equipmanage.h"

EquipManage::EquipManage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EquipManage)
{
    ui->setupUi(this);
}

EquipManage::~EquipManage()
{
    delete ui;
}
