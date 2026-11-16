#pragma once

#include <QMainWindow>
#include "ui_CreateTournamentWindow.h"
#include "TournamentBridge.h"

class CreateTournamentWindow : public QMainWindow
{
	Q_OBJECT

public:
	CreateTournamentWindow(QWidget *parent = nullptr);
	~CreateTournamentWindow();

private:
	Ui::CreateTournamentWindowClass ui;
	Tournament tournament{4, 3}; // Instance of the Tournament class to manage the tournament logic.

private slots:
	void on_addTeamButton_clicked();
	void on_deleteTeamButton_clicked();
	void on_restartSetupButton_clicked();
	void on_startMatchButton_clicked();
	void on_size4TournamentButton_clicked();
	void on_size8TournamentButton_clicked();
	void on_size16TournamentButton_clicked();
};

