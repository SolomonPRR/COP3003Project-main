#pragma once

#include <QMainWindow>
#include "ui_MatchStandings.h"

class MatchStandings : public QMainWindow
{
	Q_OBJECT

public:
	MatchStandings(QWidget *parent = nullptr);
	~MatchStandings();
	void setResults(const QString& results);

private:
	Ui::MatchStandingsClass ui;
private slots:
	void on_newMatchButton_clicked();
	void on_return2MenuButton_clicked();
};

