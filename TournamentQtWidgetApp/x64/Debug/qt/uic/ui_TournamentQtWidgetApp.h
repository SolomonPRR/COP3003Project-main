/********************************************************************************
** Form generated from reading UI file 'TournamentQtWidgetApp.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOURNAMENTQTWIDGETAPP_H
#define UI_TOURNAMENTQTWIDGETAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TournamentQtWidgetAppClass
{
public:
    QWidget *centralWidget;
    QPushButton *createTournamentButton;
    QLabel *label;
    QPushButton *exitButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TournamentQtWidgetAppClass)
    {
        if (TournamentQtWidgetAppClass->objectName().isEmpty())
            TournamentQtWidgetAppClass->setObjectName("TournamentQtWidgetAppClass");
        TournamentQtWidgetAppClass->resize(766, 310);
        centralWidget = new QWidget(TournamentQtWidgetAppClass);
        centralWidget->setObjectName("centralWidget");
        createTournamentButton = new QPushButton(centralWidget);
        createTournamentButton->setObjectName("createTournamentButton");
        createTournamentButton->setGeometry(QRect(310, 80, 151, 31));
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(210, 10, 371, 61));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        exitButton = new QPushButton(centralWidget);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(310, 120, 151, 31));
        TournamentQtWidgetAppClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TournamentQtWidgetAppClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 766, 21));
        TournamentQtWidgetAppClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TournamentQtWidgetAppClass);
        mainToolBar->setObjectName("mainToolBar");
        TournamentQtWidgetAppClass->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TournamentQtWidgetAppClass);
        statusBar->setObjectName("statusBar");
        TournamentQtWidgetAppClass->setStatusBar(statusBar);

        retranslateUi(TournamentQtWidgetAppClass);

        QMetaObject::connectSlotsByName(TournamentQtWidgetAppClass);
    } // setupUi

    void retranslateUi(QMainWindow *TournamentQtWidgetAppClass)
    {
        TournamentQtWidgetAppClass->setWindowTitle(QCoreApplication::translate("TournamentQtWidgetAppClass", "TournamentQtWidgetApp", nullptr));
        createTournamentButton->setText(QCoreApplication::translate("TournamentQtWidgetAppClass", "Create Tournament", nullptr));
        label->setText(QCoreApplication::translate("TournamentQtWidgetAppClass", "Simply Something Tournament", nullptr));
        exitButton->setText(QCoreApplication::translate("TournamentQtWidgetAppClass", "Exit Program", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TournamentQtWidgetAppClass: public Ui_TournamentQtWidgetAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOURNAMENTQTWIDGETAPP_H
