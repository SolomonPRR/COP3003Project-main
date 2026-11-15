#include "_4TeamBracketMatch.h"
#include "MatchStandings.h"

_4TeamBracketMatch::_4TeamBracketMatch(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

_4TeamBracketMatch::~_4TeamBracketMatch()
{}

void  _4TeamBracketMatch::on_calculate4MatchButton_clicked()
{
	// Implement the logic for calculating the 4-team bracket match results here
}

void  _4TeamBracketMatch::on_result4Button_clicked()
{
	auto* window = new MatchStandings(this);

	window->setAttribute(Qt::WA_DeleteOnClose);
	window->setWindowModality(Qt::ApplicationModal);
	window->show();
}

