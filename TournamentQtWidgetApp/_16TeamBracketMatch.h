#pragma once

#include <QMainWindow>
#include "ui__16TeamBracketMatch.h"

class _16TeamBracketMatch : public QMainWindow
{
	Q_OBJECT

public:
	_16TeamBracketMatch(QWidget *parent = nullptr);
	~_16TeamBracketMatch();

private:
	Ui::_16TeamBracketMatchClass ui;
};

