#include "basewidget.h"
#include "ui_basewidget.h"

BaseWidget::BaseWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BaseWidget)
    ,bisPressed(false)
{
    ui->setupUi(this);

    m_areaMovable = geometry();

    setWindowFlags(Qt::FramelessWindowHint);    // 去边框
    m_pTitlebar = new Titlebar;
    m_pBase = new Base;
    m_pStatusbar = new Statusbar;

    ui->horizon_titlebar->addWidget(m_pTitlebar);
    ui->horizon_center->addWidget(m_pBase);
    ui->horizon_statusbar->addWidget(m_pStatusbar);

    //右上角三个功能按钮的信号连接
    connect(m_pTitlebar, &Titlebar::miniSizedSignal, this, &BaseWidget::showMinimized);
    connect(m_pTitlebar, &Titlebar::maxSizedSignal, this, &BaseWidget::showMaxWindow);
    connect(m_pTitlebar, &Titlebar::closeSignal, this, &BaseWidget::close);

    //连接base信号和status槽
    connect(m_pBase,&Base::showStatus,m_pStatusbar,&Statusbar::showStatus);

    connect(m_pBase,&Base::ChangeInterfaceSize,this,&BaseWidget::ChangeInterfaceSize);

    connect(m_pBase,&Base::ChangeInterfaceBack,this,&BaseWidget::ChangeInterfaceBack);

}

void BaseWidget::showMaxWindow(){
    if(isMaximized()){
        //如果是最大化就还原
        showNormal();
    }else{
        showMaximized();
    }
}

void BaseWidget::ChangeInterfaceSize()
{
    setMinimumSize(1125, 733);
    setMaximumSize(1125, 733);
}

void BaseWidget::ChangeInterfaceBack()
{
    setMinimumSize(400, 416);
    setMaximumSize(400, 416);
}

void BaseWidget::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        posArea = event->pos();         // 获取当前鼠标在窗口所点击的位置
    }

    bisPressed = m_areaMovable.contains(posArea);
}

void BaseWidget::mouseReleaseEvent(QMouseEvent *event) {
    bisPressed = false;

    event->accept();

    QWidget::mouseReleaseEvent(event);
}


void BaseWidget::mouseMoveEvent(QMouseEvent *event) {
    //posArea 鼠标左键按下时的坐标
    //event->pos() 鼠标当前相对于窗口的位置
    //pos()获取的是窗口当前的位置
    if (bisPressed) {
        this->move(pos() + event->pos() - posArea);

    }
}


BaseWidget::~BaseWidget() {
    delete ui;
}



