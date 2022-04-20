/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *board;
    QPushButton *dealpushButton;
    QPushButton *hitpushButton;
    QPushButton *doublepushButton;
    QPushButton *staypushButton;
    QPushButton *addPlayerpushButton;
    QPushButton *exitpushButton;
    QPushButton *betpushButton;
    QPushButton *quitpushButton;
    QPushButton *redopushButton;
    QPushButton *addMoneypushButton;
    QPushButton *insureTurnpushButton;
    QLineEdit *inputBetlineEdit;
    QLineEdit *inputAddMoneylineEdit;
    QLabel *currentPlayerlabel;
    QLabel *notificationlabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        board = new QGraphicsView(centralwidget);
        board->setObjectName(QString::fromUtf8("board"));
        board->setGeometry(QRect(0, 0, 500, 500));
        dealpushButton = new QPushButton(centralwidget);
        dealpushButton->setObjectName(QString::fromUtf8("dealpushButton"));
        dealpushButton->setGeometry(QRect(510, 10, 100, 91));
        hitpushButton = new QPushButton(centralwidget);
        hitpushButton->setObjectName(QString::fromUtf8("hitpushButton"));
        hitpushButton->setGeometry(QRect(10, 510, 100, 32));
        doublepushButton = new QPushButton(centralwidget);
        doublepushButton->setObjectName(QString::fromUtf8("doublepushButton"));
        doublepushButton->setGeometry(QRect(200, 510, 100, 32));
        staypushButton = new QPushButton(centralwidget);
        staypushButton->setObjectName(QString::fromUtf8("staypushButton"));
        staypushButton->setGeometry(QRect(390, 510, 100, 32));
        addPlayerpushButton = new QPushButton(centralwidget);
        addPlayerpushButton->setObjectName(QString::fromUtf8("addPlayerpushButton"));
        addPlayerpushButton->setGeometry(QRect(660, 60, 100, 32));
        exitpushButton = new QPushButton(centralwidget);
        exitpushButton->setObjectName(QString::fromUtf8("exitpushButton"));
        exitpushButton->setGeometry(QRect(660, 10, 100, 32));
        betpushButton = new QPushButton(centralwidget);
        betpushButton->setObjectName(QString::fromUtf8("betpushButton"));
        betpushButton->setGeometry(QRect(510, 130, 100, 32));
        quitpushButton = new QPushButton(centralwidget);
        quitpushButton->setObjectName(QString::fromUtf8("quitpushButton"));
        quitpushButton->setGeometry(QRect(670, 130, 100, 32));
        redopushButton = new QPushButton(centralwidget);
        redopushButton->setObjectName(QString::fromUtf8("redopushButton"));
        redopushButton->setGeometry(QRect(670, 250, 100, 32));
        addMoneypushButton = new QPushButton(centralwidget);
        addMoneypushButton->setObjectName(QString::fromUtf8("addMoneypushButton"));
        addMoneypushButton->setGeometry(QRect(510, 200, 100, 32));
        insureTurnpushButton = new QPushButton(centralwidget);
        insureTurnpushButton->setObjectName(QString::fromUtf8("insureTurnpushButton"));
        insureTurnpushButton->setGeometry(QRect(670, 300, 100, 32));
        inputBetlineEdit = new QLineEdit(centralwidget);
        inputBetlineEdit->setObjectName(QString::fromUtf8("inputBetlineEdit"));
        inputBetlineEdit->setGeometry(QRect(620, 130, 41, 24));
        inputAddMoneylineEdit = new QLineEdit(centralwidget);
        inputAddMoneylineEdit->setObjectName(QString::fromUtf8("inputAddMoneylineEdit"));
        inputAddMoneylineEdit->setGeometry(QRect(620, 200, 41, 24));
        currentPlayerlabel = new QLabel(centralwidget);
        currentPlayerlabel->setObjectName(QString::fromUtf8("currentPlayerlabel"));
        currentPlayerlabel->setGeometry(QRect(520, 260, 141, 61));
        notificationlabel = new QLabel(centralwidget);
        notificationlabel->setObjectName(QString::fromUtf8("notificationlabel"));
        notificationlabel->setGeometry(QRect(520, 390, 261, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        dealpushButton->setText(QCoreApplication::translate("MainWindow", "Deal", nullptr));
        hitpushButton->setText(QCoreApplication::translate("MainWindow", "Hit", nullptr));
        doublepushButton->setText(QCoreApplication::translate("MainWindow", "Double", nullptr));
        staypushButton->setText(QCoreApplication::translate("MainWindow", "Stay", nullptr));
        addPlayerpushButton->setText(QCoreApplication::translate("MainWindow", "Add Player", nullptr));
        exitpushButton->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        betpushButton->setText(QCoreApplication::translate("MainWindow", "Bet", nullptr));
        quitpushButton->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        redopushButton->setText(QCoreApplication::translate("MainWindow", "Redo Turn", nullptr));
        addMoneypushButton->setText(QCoreApplication::translate("MainWindow", "Add Money", nullptr));
        insureTurnpushButton->setText(QCoreApplication::translate("MainWindow", "Insure Turn", nullptr));
        currentPlayerlabel->setText(QCoreApplication::translate("MainWindow", "Current Player Label", nullptr));
        notificationlabel->setText(QCoreApplication::translate("MainWindow", "Notification label", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
