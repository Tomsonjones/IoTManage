/********************************************************************************
** Form generated from reading UI file 'iniconfig.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INICONFIG_H
#define UI_INICONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IniConfig
{
public:

    void setupUi(QWidget *IniConfig)
    {
        if (IniConfig->objectName().isEmpty())
            IniConfig->setObjectName(QString::fromUtf8("IniConfig"));
        IniConfig->resize(400, 300);

        retranslateUi(IniConfig);

        QMetaObject::connectSlotsByName(IniConfig);
    } // setupUi

    void retranslateUi(QWidget *IniConfig)
    {
        IniConfig->setWindowTitle(QCoreApplication::translate("IniConfig", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IniConfig: public Ui_IniConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INICONFIG_H
