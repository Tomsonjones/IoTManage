#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "mysqlite.h"

namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT

public slots:
    void onRegisterButtonClicked();

public:
    explicit RegisterDialog(QWidget *parent = nullptr);
    ~RegisterDialog();

    // 获取用户输入
    QString getUsername() ;
    QString getPassword() ;
    QString getEmail() ;
    QString getPhone() ;
    QString getNickname() ;

private:
    Ui::RegisterDialog *ui;
    MySqlite *m_pMySqlite;
};

#endif // REGISTERDIALOG_H
