#include "TournamentQtWidgetApp.h"
#include <QtWidgets/QApplication>
#include "TournamentBridge.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>

int main(int argc, char* argv[])
{

    QApplication app(argc, argv);
    TournamentQtWidgetApp window;
    window.show();
    return app.exec();

}