#include "TournamentQtWidgetApp.h"
#include "CreateTournamentWindow.h"
#include <QApplication>

TournamentQtWidgetApp::TournamentQtWidgetApp(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

TournamentQtWidgetApp::~TournamentQtWidgetApp()
{}

void TournamentQtWidgetApp::on_createTournamentButton_clicked()
{
    auto* window = new CreateTournamentWindow(this);

    window->setAttribute(Qt::WA_DeleteOnClose);
    window->show();
} 

void TournamentQtWidgetApp::on_exitButton_clicked()
{
	QApplication::quit();
}