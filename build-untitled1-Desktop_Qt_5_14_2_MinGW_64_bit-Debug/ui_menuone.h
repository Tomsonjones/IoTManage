/********************************************************************************
** Form generated from reading UI file 'menuone.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUONE_H
#define UI_MENUONE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_MenuOne
{
public:
    QTableView *tableView;

    void setupUi(QDialog *MenuOne)
    {
        if (MenuOne->objectName().isEmpty())
            MenuOne->setObjectName(QString::fromUtf8("MenuOne"));
        MenuOne->resize(441, 418);
        MenuOne->setMinimumSize(QSize(441, 418));
        MenuOne->setMaximumSize(QSize(441, 418));
        tableView = new QTableView(MenuOne);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(50, 30, 300, 350));
        tableView->setMinimumSize(QSize(300, 350));
        tableView->setMaximumSize(QSize(300, 350));

        retranslateUi(MenuOne);

        QMetaObject::connectSlotsByName(MenuOne);
    } // setupUi

    void retranslateUi(QDialog *MenuOne)
    {
        MenuOne->setWindowTitle(QCoreApplication::translate("MenuOne", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuOne: public Ui_MenuOne {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUONE_H
