#include "CreateTournamentWindow.h"
#include "TournamentBridge.h"
#include "_4TeamBracketMatch.h"
#include "_8TeamBracketMatch.h"
#include <QInputDialog>
#include <QLineEdit>
#include <QMessageBox>

CreateTournamentWindow::CreateTournamentWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

CreateTournamentWindow::~CreateTournamentWindow()
{}

void CreateTournamentWindow::on_size4TournamentButton_clicked()
{
	// This is a bypass to the 4 team bracket match window. It will create a new instance of the window and show it.
	// The intended function is to select the team size only, "Start Match" opens the bracket match window with the selected team size.
	
	/*auto* window = new _4TeamBracketMatch(this);

	window->setAttribute(Qt::WA_DeleteOnClose);
	window->setWindowModality(Qt::ApplicationModal);
	window->show();*/

	ui.lineEdit->setFocus();


}

void CreateTournamentWindow::on_size8TournamentButton_clicked()
{
	// This is a bypass to the 8 team bracket match window. It will create a new instance of the window and show it.
	// The intended function is to select the team size only, "Start Match" opens the bracket match window with the selected team size.
	auto* window = new _8TeamBracketMatch(this);

	window->setAttribute(Qt::WA_DeleteOnClose);
	window->setWindowModality(Qt::ApplicationModal);
	window->show();
}

void CreateTournamentWindow::on_addTeamButton_clicked()
{
			QString name = ui.lineEdit->text().trimmed();

	bool added = tournament.addTeam(name.toStdString());

	if (added)
	{
		ui.teamListSetup->addItem(name);
		ui.lineEdit->clear();
		ui.lineEdit->setToolTip("");
	}

	else
	{
		ui.lineEdit->setToolTip(
			"Enter a team name that is not already used."
		);
		ui.lineEdit->selectAll();
	}

	ui.lineEdit->setFocus();

}

void CreateTournamentWindow::on_deleteTeamButton_clicked()
{
	// Deletes a team from the list widget in the tournament setup (Deletes from Team vector as well).
	int row = ui.teamListSetup->currentRow();
	if (row == -1) {
		QMessageBox::warning(this, "Invalid Selection", "Please select a team to delete.");

		return;
	}
	tournament.removeTeam(ui.teamListSetup->item(row)->text().toStdString()	);

	delete ui.teamListSetup->takeItem(row);
}


void CreateTournamentWindow::on_restartSetupButton_clicked()
{
	// Resets the tournament setup, clearing the list widget and Team vector of any data.

	tournament.clearTeams();

	ui.teamListSetup->clear();
	//ui.addTeamButton->clear();
	ui.addTeamButton->setFocus();

}

void CreateTournamentWindow::on_startMatchButton_clicked()
{
	// Opens the bracket match window with the selected team size (remember to validate the selection and to remove the bypass).
	// This button should be the only one that opens the bracket match window.

	const auto& teams = tournament.getTeams();

	if (teams.size() < 4) {
		QMessageBox::warning(this, "Not Enough Teams", "Please add at least 4 teams to start the match.");
		return;
	}

	auto* window = new _4TeamBracketMatch(this);

	window->setTeams(teams);

	window->setAttribute(Qt::WA_DeleteOnClose);
	window->setWindowModality(Qt::ApplicationModal);
	window->show();


}
