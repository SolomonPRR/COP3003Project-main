#pragma once

#include <QMainWindow>
#include "ui__8TeamBracketMatch.h"

class _8TeamBracketMatch : public QMainWindow
{
	Q_OBJECT

public:
	_8TeamBracketMatch(QWidget *parent = nullptr);
	~_8TeamBracketMatch();

private:
	Ui::_8TeamBracketMatchClass ui;
private slots:
	void on_calculate8MatchButton_clicked();
	void on_result8Button_clicked();
};

