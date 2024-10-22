#include "barchart.h"
#include "ui_barchart.h"

BarChart::BarChart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BarChart)
{
    ui->setupUi(this);
}

BarChart::~BarChart()
{
    delete ui;
}
