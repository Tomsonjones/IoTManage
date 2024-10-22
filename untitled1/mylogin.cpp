#include "mylogin.h"
#include "ui_mylogin.h"
#include <QDebug>

Mylogin::Mylogin(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Mylogin)
{
    ui->setupUi(this);

    Logintims=0;
    Freezetimer = new QTimer (this);

//    //执行登陆业务之前先获取账号密码
//    m_pIniConfig = new IniConfig ;
//    //m_pIniConfig->writeSettings();
//    m_pIniConfig->readSettings();
//    m_username = m_pIniConfig->m_username;
//    m_password = m_pIniConfig->m_password;

      m_pMySqlite=new MySqlite ;
//    m_username = m_pMySqlite->username;
//    m_password = m_pMySqlite->password;
//    delete m_pMySqlite;

    setWindowFlags(Qt::FramelessWindowHint);//去掉边框
    ui->lineEdit_2->setEchoMode(QLineEdit::EchoMode::Password);
    //登陆按钮信号连接
    connect(ui->pushButton,&QAbstractButton::clicked,this,&Mylogin::LoginAction);
    //注册按钮信号连接
    connect(ui->pushButton_2,&QAbstractButton::clicked,this,&Mylogin::RegisterAction);
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
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        emit display(1);
        emit display(-1);
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
    m_pMySqlite->UserRegister(ui->lineEdit->text(),ui->lineEdit_2->text());
    emit showStatus(-2);
}

void Mylogin::unfreeze(){
    ui->lineEdit->setEnabled(true);
    ui->lineEdit_2->setEnabled(true);
    ui->pushButton->setEnabled(true);
    emit showStatus(-1);
}

Mylogin::~Mylogin()
{
    delete m_pMySqlite;
    delete ui;
}



