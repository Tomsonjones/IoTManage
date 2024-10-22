#include "statusbar.h"
#include "ui_statusbar.h"

Statusbar::Statusbar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statusbar)
{
    ui->setupUi(this);

}

void Statusbar::showStatus(int a){
    if(a==-1){
        ui->label_mes->clear();
        return;
    }
    if(a==-2){
        ui->label_mes->setText("注册成功");
        return;
    }
    if(a==-3){
        ui->label_mes->setText("注册失败");
        return;
    }
    int times=3- a;
    ui->label_mes->setText(QString("用户名或密码错误,剩余%1次机会").arg(times));

}

Statusbar::~Statusbar()
{
    delete ui;
}
