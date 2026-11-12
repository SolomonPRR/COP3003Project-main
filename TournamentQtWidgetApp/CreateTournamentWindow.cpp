#include "CreateTournamentWindow.h"
#include <QmessageBox>
#include <QPushButton>

CreateTournamentWindow::CreateTournamentWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.addTeamButton, &QPushButton::clicked,
        this, [this]()
        {
            QString name = ui.teamNameEdit->text().trimmed();

            bool added = tournament.addTeam(name.toStdString());

            if (added)
            {
                ui.teamList->addItem(name);
                ui.teamNameEdit->clear();
            }
            else
            {
                QMessageBox::warning(
                    this,
                    "Cannot Add Team",
                    "Enter a team name that is not already used."
                );
            }
        });
}

CreateTournamentWindow::~CreateTournamentWindow()
{}

