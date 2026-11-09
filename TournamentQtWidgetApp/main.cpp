#include "TournamentQtWidgetApp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    TournamentQtWidgetApp window;
    window.show();
    return app.exec();
}
