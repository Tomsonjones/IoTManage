#include "operationrecord.h"
#include "ui_operationrecord.h"

OperationRecord::OperationRecord(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OperationRecord)
{
    ui->setupUi(this);
}

OperationRecord::~OperationRecord()
{
    delete ui;
}
