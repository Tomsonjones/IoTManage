#ifndef MYSQLITE_H
#define MYSQLITE_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlField>
#include <QDebug>
#include <QRegularExpression>

namespace Ui {
class MySqlite;
}

class MySqlite : public QWidget
{
    Q_OBJECT

public:
    explicit MySqlite(QWidget *parent = nullptr);
    ~MySqlite();
    bool LoginCheck(QString username,QString password);
    bool UserRegister(QString username, QString password, QString email, QString phone, QString nickname);


private:
    Ui::MySqlite *ui;
};

#endif // MYSQLITE_H
