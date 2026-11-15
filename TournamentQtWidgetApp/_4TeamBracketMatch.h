#pragma once

#include <QMainWindow>
#include "ui__4TeamBracketMatch.h"

class _4TeamBracketMatch : public QMainWindow
{
	Q_OBJECT

public:
	_4TeamBracketMatch(QWidget *parent = nullptr);
	~_4TeamBracketMatch();

private:
	Ui::_4TeamBracketMatchClass ui;
private slots:
	void on_calculate4MatchButton_clicked();
	void on_result4Button_clicked();
};

