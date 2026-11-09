/********************************************************************************
** Form generated from reading UI file 'CreateTournamentWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATETOURNAMENTWINDOW_H
#define UI_CREATETOURNAMENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateTournamentWindowClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QListWidget *listWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CreateTournamentWindowClass)
    {
        if (CreateTournamentWindowClass->objectName().isEmpty())
            CreateTournamentWindowClass->setObjectName("CreateTournamentWindowClass");
        CreateTournamentWindowClass->resize(951, 451);
        centralWidget = new QWidget(CreateTournamentWindowClass);
        centralWidget->setObjectName("centralWidget");
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(360, 20, 231, 41));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(40, 70, 871, 211));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 30, 111, 31));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(790, 30, 121, 31));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(40, 290, 281, 31));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(330, 290, 121, 31));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(330, 330, 121, 31));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(40, 330, 281, 31));
        CreateTournamentWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CreateTournamentWindowClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 951, 21));
        CreateTournamentWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CreateTournamentWindowClass);
        mainToolBar->setObjectName("mainToolBar");
        CreateTournamentWindowClass->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CreateTournamentWindowClass);
        statusBar->setObjectName("statusBar");
        CreateTournamentWindowClass->setStatusBar(statusBar);

        retranslateUi(CreateTournamentWindowClass);

        QMetaObject::connectSlotsByName(CreateTournamentWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *CreateTournamentWindowClass)
    {
        CreateTournamentWindowClass->setWindowTitle(QCoreApplication::translate("CreateTournamentWindowClass", "CreateTournamentWindow", nullptr));
        label->setText(QCoreApplication::translate("CreateTournamentWindowClass", "Tournament Teams", nullptr));
        pushButton->setText(QCoreApplication::translate("CreateTournamentWindowClass", "Restart", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CreateTournamentWindowClass", "Start Match", nullptr));
        pushButton_3->setText(QCoreApplication::translate("CreateTournamentWindowClass", "Add Team", nullptr));
        pushButton_4->setText(QCoreApplication::translate("CreateTournamentWindowClass", "Delete Team", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateTournamentWindowClass: public Ui_CreateTournamentWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATETOURNAMENTWINDOW_H
