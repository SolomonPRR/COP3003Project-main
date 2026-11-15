#include "_8TeamBracketMatch.h"
#include "MatchStandings.h"

_8TeamBracketMatch::_8TeamBracketMatch(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

_8TeamBracketMatch::~_8TeamBracketMatch()
{}

void  _8TeamBracketMatch::on_calculate8MatchButton_clicked()
{
	// Implement the logic for calculating the 8-team bracket match results here
}

void  _8TeamBracketMatch::on_result8Button_clicked()
{
	auto* window = new MatchStandings(this);

	window->setAttribute(Qt::WA_DeleteOnClose);
	window->setWindowModality(Qt::ApplicationModal);
	window->show();
}

