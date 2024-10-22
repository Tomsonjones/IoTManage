/********************************************************************************
** Form generated from reading UI file 'basewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASEWIDGET_H
#define UI_BASEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BaseWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizon_titlebar;
    QHBoxLayout *horizon_center;
    QHBoxLayout *horizon_statusbar;

    void setupUi(QDialog *BaseWidget)
    {
        if (BaseWidget->objectName().isEmpty())
            BaseWidget->setObjectName(QString::fromUtf8("BaseWidget"));
        BaseWidget->resize(441, 345);
        verticalLayout = new QVBoxLayout(BaseWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizon_titlebar = new QHBoxLayout();
        horizon_titlebar->setObjectName(QString::fromUtf8("horizon_titlebar"));

        verticalLayout->addLayout(horizon_titlebar);

        horizon_center = new QHBoxLayout();
        horizon_center->setObjectName(QString::fromUtf8("horizon_center"));

        verticalLayout->addLayout(horizon_center);

        horizon_statusbar = new QHBoxLayout();
        horizon_statusbar->setObjectName(QString::fromUtf8("horizon_statusbar"));

        verticalLayout->addLayout(horizon_statusbar);


        retranslateUi(BaseWidget);

        QMetaObject::connectSlotsByName(BaseWidget);
    } // setupUi

    void retranslateUi(QDialog *BaseWidget)
    {
        BaseWidget->setWindowTitle(QCoreApplication::translate("BaseWidget", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BaseWidget: public Ui_BaseWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASEWIDGET_H
