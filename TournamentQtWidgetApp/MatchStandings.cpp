#include "MatchStandings.h"
#include "TournamentQtWidgetApp.h"
#include "CreateTournamentWindow.h"

MatchStandings::MatchStandings(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

MatchStandings::~MatchStandings()
{}

void MatchStandings::on_newMatchButton_clicked()
{
	auto* window = new CreateTournamentWindow(this);

	window->setAttribute(Qt::WA_DeleteOnClose);
	window->setWindowModality(Qt::ApplicationModal);
	window->show();
}

void  MatchStandings::on_return2MenuButton_clicked()
{
	auto* window = new TournamentQtWidgetApp(this);

	window->setAttribute(Qt::WA_DeleteOnClose);
	window->setWindowModality(Qt::ApplicationModal);
	window->show();
}