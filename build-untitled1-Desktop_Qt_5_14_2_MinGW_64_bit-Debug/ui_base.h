/********************************************************************************
** Form generated from reading UI file 'base.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASE_H
#define UI_BASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Base
{
public:

    void setupUi(QDialog *Base)
    {
        if (Base->objectName().isEmpty())
            Base->setObjectName(QString::fromUtf8("Base"));
        Base->resize(520, 411);

        retranslateUi(Base);

        QMetaObject::connectSlotsByName(Base);
    } // setupUi

    void retranslateUi(QDialog *Base)
    {
        Base->setWindowTitle(QCoreApplication::translate("Base", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Base: public Ui_Base {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASE_H
