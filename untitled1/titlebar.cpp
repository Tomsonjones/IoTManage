#include "titlebar.h"
#include "ui_titlebar.h"

Titlebar::Titlebar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Titlebar)
{
    ui->setupUi(this);

    connect(ui->pushButton,&QAbstractButton::clicked,this,&Titlebar::miniSizedSignal);
    connect(ui->pushButton_2,&QAbstractButton::clicked,this,&Titlebar::maxSizedSignal);
    connect(ui->pushButton_3,&QAbstractButton::clicked,this,&Titlebar::closeSignal);
}

Titlebar::~Titlebar()
{
    delete ui;
}
