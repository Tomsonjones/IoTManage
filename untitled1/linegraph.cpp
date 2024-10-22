#include "linegraph.h"
#include "ui_linegraph.h"

LineGraph::LineGraph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LineGraph)
{
    ui->setupUi(this);
}

LineGraph::~LineGraph()
{
    delete ui;
}
