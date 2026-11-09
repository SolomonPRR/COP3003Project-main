#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TournamentQtWidgetApp.h"

class TournamentQtWidgetApp : public QMainWindow
{
    Q_OBJECT

public:
    TournamentQtWidgetApp(QWidget *parent = nullptr);
    ~TournamentQtWidgetApp();

private:
    Ui::TournamentQtWidgetAppClass ui;
private slots:
    void on_createTournamentButton_clicked();
	void on_exitButton_clicked();
};

