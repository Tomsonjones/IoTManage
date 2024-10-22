#include "mysqlite.h"
#include "ui_mysqlite.h"

MySqlite::MySqlite(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MySqlite)
{
    ui->setupUi(this);

    //    //创建一个新的数据库连接，并指定使用 SQLite 数据库引擎
    //    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //    //连接数据库
    //    db.setDatabaseName("users.db");
    //    if (!db.open()) {
    //        qDebug() << "Error: Could not connect to database.";
    //        return ;
    //    }

    //    //建表
    //    QSqlQuery query;
    //    if (!query.exec("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, username TEXT, password TEXT)")) {
    //        qDebug() << "Error: Could not create table:" << query.lastError();
    //        return ;
    //    }

    //    //插入数据
    //    query.prepare("INSERT INTO users (username, password) VALUES (?, ?)");
    //    query.addBindValue("asd");
    //    query.addBindValue("123");
    //    if (!query.exec()) {
    //        qDebug() << "Error: Could not insert record:" << query.lastError();
    //        return ;
    //    }

    //      //查询数据
    //    if (!query.exec("SELECT * FROM users")) {
    //        qDebug() << "Error: Could not query table:" << query.lastError();
    //        return ;
    //    }

    //    //读取表中数据
    //    while (query.next()) {
    //        QSqlRecord record = query.record();

    //        int id = record.value("id").toInt();
    //        username = record.value("username").toString();
    //        password = record.value("password").toString();


    //    }
    //    db.close();
}

MySqlite::~MySqlite()
{
    delete ui;
}

bool MySqlite::LoginCheck(QString username, QString password)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //连接数据库
    db.setDatabaseName("users.db");
    if (!db.open()) {
        qDebug() << "Error: Could not connect to database.";
        return false ;
    }

    QSqlQuery query;

    //查询数据
    if (!query.exec("SELECT * FROM users")) {
        qDebug() << "Error: Could not query table:" << query.lastError();
        return false;
    }

    //读取表中数据
    while (query.next()) {
        QSqlRecord record = query.record();

        //        int id = record.value("id").toInt();
        //        record.value("username").toString();
        //        record.value("password").toString();

        if( record.value("username").toString() == username && record.value("password").toString() == password){
            return true;
        }
    }
    return false;
    db.close();
}

void MySqlite::UserRegister(QString username, QString password)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //连接数据库
    db.setDatabaseName("users.db");
    if (!db.open()) {
        qDebug() << "Error: Could not connect to database.";
        return  ;
    }
    QSqlQuery query;
    //插入数据
    query.prepare("INSERT INTO users (username, password) VALUES (?, ?)");
    query.addBindValue(username);
    query.addBindValue(password);
    if (!query.exec()) {
        qDebug() << "Error: Could not insert record:" << query.lastError();
        return ;
    }
    db.close();
}
