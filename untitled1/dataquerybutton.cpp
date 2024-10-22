#include "dataquerybutton.h"
#include "ui_dataquerybutton.h"

DataQueryButton::DataQueryButton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataQueryButton)
{
    ui->setupUi(this);
}

DataQueryButton::~DataQueryButton()
{
    delete ui;
}
