#include "mylogin.h"
#include "ui_mylogin.h"
#include <QDebug>
#include "usermanagementlow.h"

QString CurrentUsername;
QString CurrentRole;

Mylogin::Mylogin(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Mylogin)
{
    ui->setupUi(this);

    Logintims=0;
    Freezetimer = new QTimer (this);


    m_pMySqlite=new MySqlite ;

    setWindowFlags(Qt::FramelessWindowHint);//去掉边框
    ui->lineEdit_2->setEchoMode(QLineEdit::EchoMode::Password);
    //登陆按钮信号连接
    connect(ui->pushButton,&QAbstractButton::clicked,this,&Mylogin::LoginAction);
    //注册按钮信号连接
    connect(ui->pushButton_2,&QAbstractButton::clicked,this,&Mylogin::openRegisterDialog);
    //三次输错密码冻结一段时间
    connect(Freezetimer,&QTimer::timeout,this,&Mylogin::unfreeze);

}

void Mylogin::LoginAction(){


    if(Logintims==3){
        ui->lineEdit->setEnabled(false);
        ui->lineEdit_2->setEnabled(false);
        ui->pushButton->setEnabled(false);
        Logintims=0;
        Freezetimer->start(3000);
        return;
    }

    //    if(ui->lineEdit->text()==m_username && ui->lineEdit_2->text()==m_password){
    if(m_pMySqlite->LoginCheck(ui->lineEdit->text(),ui->lineEdit_2->text())){
        //登陆成功

        emit display(1);
        emit display(-1);
        CurrentUsername = ui->lineEdit->text();
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        m_pUserManagementLow->loadUserData(CurrentUsername);
    }else{
        Logintims  = Logintims + 1;
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();

        emit showStatus(Logintims);
    }

}

void Mylogin::RegisterAction()
{
    if(ui->lineEdit->text()=="" || ui->lineEdit_2->text()==""){
        emit showStatus(-3);
        return;
    }
    ui->lineEdit->text();
    ui->lineEdit_2->text();

    emit showStatus(-2);
}

void Mylogin::unfreeze(){
    ui->lineEdit->setEnabled(true);
    ui->lineEdit_2->setEnabled(true);
    ui->pushButton->setEnabled(true);
    emit showStatus(-1);
}

void Mylogin::openRegisterDialog()
{
    RegisterDialog dialog(this);

    // 通过 exec() 打开对话框，并等待用户点击确定或取消
    if (dialog.exec() == QDialog::Accepted) {

    } else {

    }
}




Mylogin::~Mylogin()
{
    delete m_pMySqlite;
    delete ui;
}



