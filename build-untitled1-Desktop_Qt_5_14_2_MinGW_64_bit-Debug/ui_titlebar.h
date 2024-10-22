/********************************************************************************
** Form generated from reading UI file 'titlebar.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITLEBAR_H
#define UI_TITLEBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Titlebar
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelicon;
    QLabel *labeltitle;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *Titlebar)
    {
        if (Titlebar->objectName().isEmpty())
            Titlebar->setObjectName(QString::fromUtf8("Titlebar"));
        Titlebar->resize(364, 51);
        gridLayout = new QGridLayout(Titlebar);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelicon = new QLabel(Titlebar);
        labelicon->setObjectName(QString::fromUtf8("labelicon"));

        horizontalLayout->addWidget(labelicon);

        labeltitle = new QLabel(Titlebar);
        labeltitle->setObjectName(QString::fromUtf8("labeltitle"));

        horizontalLayout->addWidget(labeltitle);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(Titlebar);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(30, 30));
        pushButton->setMaximumSize(QSize(30, 30));
        pushButton->setSizeIncrement(QSize(30, 30));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(Titlebar);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(30, 30));
        pushButton_2->setMaximumSize(QSize(30, 30));
        pushButton_2->setSizeIncrement(QSize(30, 30));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(Titlebar);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(30, 30));
        pushButton_3->setMaximumSize(QSize(30, 30));
        pushButton_3->setSizeIncrement(QSize(30, 30));

        horizontalLayout->addWidget(pushButton_3);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(Titlebar);

        QMetaObject::connectSlotsByName(Titlebar);
    } // setupUi

    void retranslateUi(QDialog *Titlebar)
    {
        Titlebar->setWindowTitle(QCoreApplication::translate("Titlebar", "Dialog", nullptr));
        labelicon->setText(QCoreApplication::translate("Titlebar", "*\347\231\273\345\275\225\347\263\273\347\273\237", nullptr));
        labeltitle->setText(QCoreApplication::translate("Titlebar", "*", nullptr));
        pushButton->setText(QCoreApplication::translate("Titlebar", "-", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Titlebar", "\342\226\241", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Titlebar", "X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Titlebar: public Ui_Titlebar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITLEBAR_H
