#ifndef BASE_H
#define BASE_H

#include <QDialog>
#include <QStackedLayout>
#include "menuone.h"
#include "mylogin.h"

namespace Ui {
class Base;
}

class Base : public QDialog
{
    Q_OBJECT

public:
    explicit Base(QWidget *parent = nullptr);
    ~Base();

signals:
    void showStatus(int a);
    void ChangeInterfaceSize();
    void ChangeInterfaceBack();

private:
    Ui::Base *ui;
    MenuOne *m_menuone;
    Mylogin *m_mylogin;
    QStackedLayout *m_pStackedLayout;

};

#endif // BASE_H
