#pragma once

#include <QMainWindow>
#include "ui_CreateTournamentWindow.h"

class CreateTournamentWindow : public QMainWindow
{
	Q_OBJECT

public:
	CreateTournamentWindow(QWidget *parent = nullptr);
	~CreateTournamentWindow();

private:
	Ui::CreateTournamentWindowClass ui;
	Tournament tournament ; 

};

