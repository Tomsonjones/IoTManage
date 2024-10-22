#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include <QDialog>
#include <QPoint>
#include <QMouseEvent>
#include <QRect>
#include <QSettings>

#include "titlebar.h"
#include "base.h"
#include "statusbar.h"

namespace Ui {
class BaseWidget;
}

class BaseWidget : public QDialog
{
    Q_OBJECT

public:
    explicit BaseWidget(QWidget *parent = nullptr);
    ~BaseWidget();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
public slots:
    void showMaxWindow();
    void ChangeInterfaceSize();
    void ChangeInterfaceBack();
private:
    Ui::BaseWidget *ui;

    Titlebar *m_pTitlebar;
    Base *m_pBase;
    Statusbar *m_pStatusbar;

    bool bisPressed;
    QPoint posArea;         // 鼠标点击的位置
    QRect m_areaMovable;    // 当前区域

};

#endif // BASEWIDGET_H
