#ifndef MYLOGIN_H
#define MYLOGIN_H

#include "menuone.h"
#include "iniconfig.h"
#include "mysqlite.h"

#include <QStackedLayout>
#include <QTimer>
#include <QFile>
#include <QSettings>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Mylogin; }
QT_END_NAMESPACE

class Mylogin : public QWidget
{
    Q_OBJECT

public:
    Mylogin(QWidget *parent = nullptr);
    ~Mylogin();

public slots:
    void LoginAction();
    void RegisterAction();
    void unfreeze();

signals:
    void display(int a);
    void showStatus(int a);

private:
    Ui::Mylogin *ui;

    int Logintims;
    QString m_username;
    QString m_password;
    QTimer *Freezetimer;
    //IniConfig *m_pIniConfig;
    MySqlite *m_pMySqlite;
};
#endif // MYLOGIN_H
