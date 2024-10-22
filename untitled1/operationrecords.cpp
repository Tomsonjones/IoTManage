#include "operationrecords.h"
#include "ui_operationrecords.h"

OperationRecords::OperationRecords(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OperationRecords)
{
    ui->setupUi(this);
}

OperationRecords::~OperationRecords()
{
    delete ui;
}
