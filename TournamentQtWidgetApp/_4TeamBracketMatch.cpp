#include "_4TeamBracketMatch.h"
#include "CreateTournamentWindow.h"
#include "ui__4TeamBracketMatch.h"
#include "TournamentBridge.h"
#include "MatchStandings.h"
#include <QMessageBox>
#include <QString>

_4TeamBracketMatch::_4TeamBracketMatch(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// Enable final scores after the starting matches finish.
	ui.match2Team1A->setEnabled(false);
	ui.match2Team2A->setEnabled(false);

	ui.match2Team1A->setReadOnly(true);
	ui.match2Team2A->setReadOnly(true);
	ui.matchWinnerA->setReadOnly(true);
}

_4TeamBracketMatch::~_4TeamBracketMatch()
{}

void _4TeamBracketMatch::setTeams(const std::vector<Team>& teamList)
{
	teams = teamList;

	QList<QComboBox*> boxes = {
		ui.match1Team1A,
		ui.match1Team2A,
		ui.match1Team3A,
		ui.match1Team4A
	};

	// Set each box to containt (select) as a default option then add the team names
	for (QComboBox* box : boxes) {
		box->clear();
		box->addItem(QString::fromStdString("(Select)"));
		for (Team team : teams) {
			box->addItem(QString::fromStdString(team.getName()));
		}
	}

}


void  _4TeamBracketMatch::on_calculate4MatchButton_clicked()
{
	// Implementaion logic used for  calculating the 4-team bracket match results 

	if (tournamentFinished) {
		return;
	}

	// FIRST CLICK: semifinals
	if (!finalistsReady) {
		int score1 = ui.match1Score1A->value();
		int score2 = ui.match1Score2A->value();
		int score3 = ui.match1Score3A->value();
		int score4 = ui.match1Score4A->value();

		if (score1 == score2 || score3 == score4) {
			QMessageBox::warning(
				this, "Tied Match",
				"Resolve any ties before continuing.");
			return;
		}

		if (ui.match1Team1A->currentIndex() == 0 ||
			ui.match1Team2A->currentIndex() == 0 ||
			ui.match1Team3A->currentIndex() == 0 ||
			ui.match1Team4A->currentIndex() == 0) {
			QMessageBox::warning(
				this, "Incomplete Selection",
				"Select a team for each match.");
			return;
		}
		// Check that no two selections are the same team
		else if (ui.match1Team1A->currentText() == ui.match1Team2A->currentText() ||
			ui.match1Team1A->currentText() == ui.match1Team3A->currentText() ||
			ui.match1Team1A->currentText() == ui.match1Team4A->currentText() ||
			ui.match1Team2A->currentText() == ui.match1Team3A->currentText() ||
			ui.match1Team2A->currentText() == ui.match1Team4A->currentText() ||
			ui.match1Team3A->currentText() == ui.match1Team4A->currentText()) {
			QMessageBox::warning(
				this, "Duplicate Teams",
				"You have two or more of the same Team.");
			return;
		}

		// Creates matches with current Match class
		matches.clear();		


		// Check which teams are in which dropdown and store them in the matches vector.
		Team match1Team1("");
		Team match1Team2("");
		Team match2Team1("");
		Team match2Team2("");
			
		for (const Team& team : teams) {
			if (team.getName() == ui.match1Team1A->currentText().toStdString()) {
				match1Team1 = team;
			}
			else if (team.getName() == ui.match1Team2A->currentText().toStdString()) {
				match1Team2 = team;
			}
			else if (team.getName() == ui.match1Team3A->currentText().toStdString()) {
				match2Team1 = team;
			}
			else if (team.getName() == ui.match1Team4A->currentText().toStdString()) {
				match2Team2 = team;
			}
		}

		matches.push_back(Match(match1Team1, match1Team2));
		matches.push_back(Match(match2Team1, match2Team2));

		// Store scores using addPoints().
		matches[0].addPoints(1, score1);
		matches[0].addPoints(2, score2);

		matches[1].addPoints(1, score3);
		matches[1].addPoints(2, score4);

		// Start with the first team from each match.
		Team finalist1 = matches[0].getTeam(1);
		Team finalist2 = matches[1].getTeam(1);

		// Using Match to determine which team won
		if (matches[0].getResult(1) == "LOSS") {
			finalist1 = matches[0].getTeam(2);
		}

		if (matches[1].getResult(1) == "LOSS") {
			finalist2 = matches[1].getTeam(2);
		}

		// Create the final using the Winning teams.
		matches.push_back(Match(finalist1, finalist2));

		ui.match2Team1A->setText(
			QString::fromStdString(finalist1.getName()));

		ui.match2Team2A->setText(
			QString::fromStdString(finalist2.getName()));

		ui.match1Score1A->setEnabled(false);
		ui.match1Score2A->setEnabled(false);
		ui.match1Score3A->setEnabled(false);
		ui.match1Score4A->setEnabled(false);

		ui.match2Score1A->setEnabled(true);
		ui.match2Score2A->setEnabled(true);

		finalistsReady = true;

		ui.calculate4MatchButton->setText("Calculate Final");
		return;
	}

	// SECOND CLICK: final
	int finalScore1 = ui.match2Score1A->value();
	int finalScore2 = ui.match2Score2A->value();

	if (finalScore1 == finalScore2) {
		QMessageBox::warning(
			this, "Tied Match",
			"Resolve the tie before continuing.");
		return;
	}

	matches[2].addPoints(1, finalScore1);
	matches[2].addPoints(2, finalScore2);

	//determines who the winner is, most likely move to .h, for testing we implement here
	Team winner = matches[2].getTeam(1);

	if (matches[2].getResult(1) == "LOSS") {
		winner = matches[2].getTeam(2);
	}

	ui.matchWinnerA->setText(
		QString::fromStdString(winner.getName()));

	ui.match2Score1A->setEnabled(false);
	ui.match2Score2A->setEnabled(false);

	tournamentFinished = true;

	ui.calculate4MatchButton->setText("Tournament Complete");
	ui.calculate4MatchButton->setEnabled(false);
}



void  _4TeamBracketMatch::on_result4Button_clicked()
{
	/*auto* window = new MatchStandings(this);

	window->setAttribute(Qt::WA_DeleteOnClose);
	window->setWindowModality(Qt::ApplicationModal);
	window->show();*/

	//work in progress, still determining what it will actually show

	if (!tournamentFinished) {
		QMessageBox::warning(
			this, "Tournament Incomplete",
			"Finish the tournament first.");
		return;
	}
	QString results = "4-TEAM TOURNAMENT RESULTS\n\n";
		for (int i = 0; i < 3; i++) {
			if (i == 2) {
				results += "FINAL\n";
			}
			else {
				results += "Team results "
				 + QString::number(i + 1) + " \n";
			}

			results += QString::fromStdString(
				matches[i].getTeam(1).getName());

			results += " : "
				+ QString::number(matches[i].getScore(1)) + "\n";
			
			results += QString::fromStdString(
					matches[i].getTeam(2).getName());
			
			results += " : "
					+ QString::number(matches[i].getScore(2)) + "\n\n";
		}
	//ditto
	Team winner = matches[2].getTeam(1);
	if (matches[2].getResult(1) == "LOSS"){
		winner = matches[2].getTeam(2);
	}
	
	results += "Winner: "
		 + QString::fromStdString(winner.getName());
	
	auto* window = new MatchStandings(this);
	
	window->setResults(results);
	window->setAttribute(Qt::WA_DeleteOnClose);
	window->setWindowModality(Qt::ApplicationModal);
	window->show();
}

