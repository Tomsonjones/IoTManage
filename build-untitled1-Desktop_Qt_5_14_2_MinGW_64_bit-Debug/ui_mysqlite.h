/********************************************************************************
** Form generated from reading UI file 'mysqlite.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYSQLITE_H
#define UI_MYSQLITE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MySqlite
{
public:

    void setupUi(QWidget *MySqlite)
    {
        if (MySqlite->objectName().isEmpty())
            MySqlite->setObjectName(QString::fromUtf8("MySqlite"));
        MySqlite->resize(400, 300);

        retranslateUi(MySqlite);

        QMetaObject::connectSlotsByName(MySqlite);
    } // setupUi

    void retranslateUi(QWidget *MySqlite)
    {
        MySqlite->setWindowTitle(QCoreApplication::translate("MySqlite", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MySqlite: public Ui_MySqlite {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYSQLITE_H
