/********************************************************************************
** Form generated from reading UI file 'statusbar.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATUSBAR_H
#define UI_STATUSBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Statusbar
{
public:
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_mes;

    void setupUi(QDialog *Statusbar)
    {
        if (Statusbar->objectName().isEmpty())
            Statusbar->setObjectName(QString::fromUtf8("Statusbar"));
        Statusbar->resize(318, 52);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font.setPointSize(7);
        font.setBold(false);
        font.setWeight(50);
        Statusbar->setFont(font);
        horizontalLayout_2 = new QHBoxLayout(Statusbar);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_mes = new QLabel(Statusbar);
        label_mes->setObjectName(QString::fromUtf8("label_mes"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Agency FB"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        label_mes->setFont(font1);
        label_mes->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_mes);


        retranslateUi(Statusbar);

        QMetaObject::connectSlotsByName(Statusbar);
    } // setupUi

    void retranslateUi(QDialog *Statusbar)
    {
        Statusbar->setWindowTitle(QCoreApplication::translate("Statusbar", "Dialog", nullptr));
        label_mes->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Statusbar: public Ui_Statusbar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATUSBAR_H
