#pragma once

#include <QMainWindow>
#include "ui_MatchStandings.h"

class MatchStandings : public QMainWindow
{
	Q_OBJECT

public:
	MatchStandings(QWidget *parent = nullptr);
	~MatchStandings();

private:
	Ui::MatchStandingsClass ui;
private slots:
	void on_newMatchButton_clicked();
	void on_return2MenuButton_clicked();
};

