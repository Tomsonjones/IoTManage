#include "iniconfig.h"
#include "ui_iniconfig.h"

IniConfig::IniConfig(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IniConfig)
{
    ui->setupUi(this);
    //读取文件
    m_pSettings=new QSettings(":/config.ini",QSettings::Format::IniFormat);
    //把文件信息读取到公有字符串中

}

IniConfig::~IniConfig()
{
    delete ui;
}

void IniConfig::writeSettings()
{
    m_pSettings->setValue("UserInfo/a", "123");
    m_pSettings->setValue("UserInfo/b", "asd");

}

void IniConfig::readSettings()
{
    m_username=m_pSettings->value("UserInfo/username", QByteArray()).toByteArray();
    m_password=m_pSettings->value("UserInfo/password", QByteArray()).toByteArray();

}
