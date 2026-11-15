#include "CreateTournamentWindow.h"
#include "_4TeamBracketMatch.h"
#include "_8TeamBracketMatch.h"
#include "_16TeamBracketMatch.h"

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
	auto* window = new _4TeamBracketMatch(this);

	window->setAttribute(Qt::WA_DeleteOnClose);
	window->setWindowModality(Qt::ApplicationModal);
	window->show();
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

void CreateTournamentWindow::on_size16TournamentButton_clicked()
{
	// Will be deleted, pay no attention, considering removing 16 team size.
	auto* window = new _16TeamBracketMatch(this);

	window->setAttribute(Qt::WA_DeleteOnClose);
	window->setWindowModality(Qt::ApplicationModal);
	window->show();
}

void CreateTournamentWindow::on_addTeamButton_clicked()
{
	// Adds a team to the list widget in the tournament setup (Adds to Team vector as well).
}

void CreateTournamentWindow::on_deleteTeamButton_clicked()
{
	// Deletes a team from the list widget in the tournament setup (Deletes from Team vector as well).
}

void CreateTournamentWindow::on_restartSetupButton_clicked()
{
	// Resets the tournament setup, clearing the list widget and Team vector of any data.
}

void CreateTournamentWindow::on_startMatchButton_clicked()
{
	// Opens the bracket match window with the selected team size (remember to validate the selection and to remove the bypass).
	// This button should be the only one that opens the bracket match window.
}
