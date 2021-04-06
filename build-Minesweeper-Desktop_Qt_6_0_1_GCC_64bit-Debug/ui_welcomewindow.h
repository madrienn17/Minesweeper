/********************************************************************************
** Form generated from reading UI file 'welcomewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMEWINDOW_H
#define UI_WELCOMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WelcomeWindow
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_4;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout_2;
    QSpinBox *ySpin;
    QSpinBox *mineSpin;
    QSpinBox *xSpin;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *exitBtn;
    QPushButton *startBtn;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QWidget *WelcomeWindow)
    {
        if (WelcomeWindow->objectName().isEmpty())
            WelcomeWindow->setObjectName(QString::fromUtf8("WelcomeWindow"));
        WelcomeWindow->setEnabled(true);
        WelcomeWindow->resize(323, 366);
        verticalLayout = new QVBoxLayout(WelcomeWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        label_4 = new QLabel(WelcomeWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        ySpin = new QSpinBox(WelcomeWindow);
        ySpin->setObjectName(QString::fromUtf8("ySpin"));
        ySpin->setMinimum(10);

        gridLayout_2->addWidget(ySpin, 1, 1, 1, 1);

        mineSpin = new QSpinBox(WelcomeWindow);
        mineSpin->setObjectName(QString::fromUtf8("mineSpin"));
        mineSpin->setMinimum(10);

        gridLayout_2->addWidget(mineSpin, 2, 1, 1, 1);

        xSpin = new QSpinBox(WelcomeWindow);
        xSpin->setObjectName(QString::fromUtf8("xSpin"));
        xSpin->setMinimum(10);

        gridLayout_2->addWidget(xSpin, 0, 1, 1, 1);

        label = new QLabel(WelcomeWindow);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(WelcomeWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(WelcomeWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        exitBtn = new QPushButton(WelcomeWindow);
        exitBtn->setObjectName(QString::fromUtf8("exitBtn"));

        horizontalLayout->addWidget(exitBtn);

        startBtn = new QPushButton(WelcomeWindow);
        startBtn->setObjectName(QString::fromUtf8("startBtn"));

        horizontalLayout->addWidget(startBtn);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);


        retranslateUi(WelcomeWindow);

        QMetaObject::connectSlotsByName(WelcomeWindow);
    } // setupUi

    void retranslateUi(QWidget *WelcomeWindow)
    {
        WelcomeWindow->setWindowTitle(QCoreApplication::translate("WelcomeWindow", "Minesweeper", nullptr));
        label_4->setText(QCoreApplication::translate("WelcomeWindow", "Select the dimmensions for your gameboard:", nullptr));
        label->setText(QCoreApplication::translate("WelcomeWindow", "Row nr.", nullptr));
        label_2->setText(QCoreApplication::translate("WelcomeWindow", "Column nr.", nullptr));
        label_3->setText(QCoreApplication::translate("WelcomeWindow", "Nr. of mines", nullptr));
        exitBtn->setText(QCoreApplication::translate("WelcomeWindow", "Exit", nullptr));
        startBtn->setText(QCoreApplication::translate("WelcomeWindow", "Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WelcomeWindow: public Ui_WelcomeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMEWINDOW_H
