#pragma once

#include <QMainWindow>
#include "ui__4TeamBracketMatch.h"
#include "TournamentBridge.h"
#include <vector>


class _4TeamBracketMatch : public QMainWindow
{
	Q_OBJECT

public:
	_4TeamBracketMatch(QWidget *parent = nullptr);
	~_4TeamBracketMatch();

	void setTeams(const std::vector<Team>& teamList);

private:
	Ui::_4TeamBracketMatchClass ui;
	std::vector<Team> teams;
	std::vector<Match> matches;

	bool finalistsReady = false;
	bool tournamentFinished = false;

private slots:
	void on_calculate4MatchButton_clicked();
	void on_result4Button_clicked();
};
