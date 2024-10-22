#include "mysqlite.h"
#include "ui_mysqlite.h"
#include <QDir>
#include "mylogin.h"


MySqlite::MySqlite(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MySqlite)
{
    ui->setupUi(this);


}

MySqlite::~MySqlite()
{
    delete ui;
}

bool MySqlite::LoginCheck(QString username, QString password)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //连接数据库
    db.setDatabaseName("D:/code/qt/IoTManage/build-untitled1-Desktop_Qt_5_14_2_MinGW_64_bit-Debug/users.db");
    if (!db.open()) {
        qDebug() << "Error: Could not connect to database.";
        return false ;
    }

    QSqlQuery query;

    qDebug() << "Current working directory:" << QDir::currentPath();
    qDebug() << "Database file path:" << QDir::currentPath() + "/users.db";

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
            CurrentRole = record.value("role").toString();
            qDebug() << CurrentRole;
            return true;
        }
    }
    db.close();
    return false; 
}

bool MySqlite::UserRegister(QString username, QString password, QString email, QString phone, QString nickname)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/code/qt/IoTManage/build-untitled1-Desktop_Qt_5_14_2_MinGW_64_bit-Debug/users.db");
    if (!db.open()) {
        qDebug() << "Error: Could not connect to database.";
        return false;
    }

    // 先确认非空
    if (username.isEmpty() || password.isEmpty() || email.isEmpty() || phone.isEmpty()) {
        qDebug() << "Error: Required fields are empty.";
        db.close();
        return false;
    }

    //正则表达式做法
    // 验证密码是否包含至少一个大写字母，且无空格
    //?=.*[A-Z] 表示至少出现一个大写字母 \\S+（非空白字符）
    //  \\S 表示非空白字符   + 加在后面 代表匹配一个或多个空白字符
    // 合起来 \\S+ 可以保证不会出现空白字符
    QRegularExpression passwordRegex("^(?=.*[A-Z])\\S+$");  // 至少包含一个大写字母，且不含空格
    if (!passwordRegex.match(password).hasMatch()) {
        qDebug() << "Error: Password must contain at least one uppercase letter and no spaces.";
        db.close();
        return false;
    }

    QSqlQuery checkQuery;
    // 检查用户名、邮箱和电话的唯一性
    checkQuery.prepare("SELECT COUNT(*) FROM users WHERE username = ? OR email = ? OR phone = ?");
    checkQuery.addBindValue(username);
    checkQuery.addBindValue(email);
    checkQuery.addBindValue(phone);

    // 执行查询
    if (!checkQuery.exec()) {
        qDebug() << "Error: Failed to check uniqueness:" << checkQuery.lastError();
        db.close();
        return false;
    }

    // 检查是否有重复的用户名、邮箱或电话
    if (checkQuery.next()) {
        int count = checkQuery.value(0).toInt();
        if (count > 0) {
            qDebug() << "Error: Username, email, or phone already exists.";
            db.close();
            return false;
        }
    }

    // 插入新用户数据
    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password, email, phone, nickname, role) "
                  "VALUES (?, ?, ?, ?, ?, 'user')");
    query.addBindValue(username);
    query.addBindValue(password);
    query.addBindValue(email);
    query.addBindValue(phone);
    query.addBindValue(nickname);

    if (!query.exec()) {
        qDebug() << "Error: Could not insert record:" << query.lastError();
        db.close();
        return false;
    }

    db.close();
    return true;
}


