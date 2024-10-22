#include "base.h"
#include "ui_base.h"

Base::Base(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Base)
{
    ui->setupUi(this);

    m_menuone = new MenuOne ;
    m_mylogin = new Mylogin ;
    m_pStackedLayout= new QStackedLayout ;
    m_pStackedLayout->addWidget(m_mylogin);
    m_pStackedLayout->addWidget(m_menuone);
    setLayout(m_pStackedLayout);
    connect(m_mylogin,&Mylogin::display,m_pStackedLayout,&QStackedLayout::setCurrentIndex);
    //界面1切换回主界面
    connect(m_menuone,&MenuOne::display,m_pStackedLayout,&QStackedLayout::setCurrentIndex);
    //status信号连接
    connect(m_mylogin,&Mylogin::showStatus,this,&Base::showStatus);
    //登陆界面成功后修改界面大小
    connect(m_mylogin,&Mylogin::display,this,&Base::ChangeInterfaceSize);
    //从登陆界面返回 改回大小
    connect(m_menuone,&MenuOne::ChangeInterfaceSize,this,&Base::ChangeInterfaceBack);
}

Base::~Base()
{
    delete ui;
}
