#ifndef USERMANAGEMENTLOW_H
#define USERMANAGEMENTLOW_H

#include <QWidget>
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlTableModel>
#include <QDialogButtonBox>
#include <QItemSelectionModel>
#include <QModelIndexList>
#include <QtWidgets>
#include <QtSql>
#include "mylogin.h"

namespace Ui {
class UserManagementLow;
}

class UserManagementLow : public QWidget
{
    Q_OBJECT
public slots:
    void ChangeAction();  // 只保留修改槽函数
public:
    explicit UserManagementLow(QWidget *parent = nullptr);
    ~UserManagementLow();
    void loadUserData(const QString& username);

private:
    Ui::UserManagementLow *ui;
    QSqlTableModel *model;
    QPushButton *ChangeButton;
    QDialogButtonBox *buttonBox;
};

#endif // USERMANAGEMENTLOW_H
