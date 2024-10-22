#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H

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

namespace Ui {
class UserManagement;
}

class UserManagement : public QWidget
{
    Q_OBJECT

public:
    explicit UserManagement(QWidget *parent = nullptr);
    ~UserManagement();

public slots:
    void DeleteAction();
    void ChangeAction();

private:
    Ui::UserManagement *ui;
    QSqlTableModel *model;
    QPushButton *quitButton;
    QPushButton *DeleteButton;
    QPushButton *ChangeButton;
    QDialogButtonBox *buttonBox;
};

#endif // USERMANAGEMENT_H
