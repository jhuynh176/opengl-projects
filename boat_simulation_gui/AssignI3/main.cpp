
#include <QApplication>

#include "MainWindow.h"

int main(int argc, char *argv[])
{
   // Q_INIT_RESOURCE(application);

    QApplication app(argc, argv);
    app.setOrganizationName("Hieu Huynh");
    app.setApplicationName("Assignment I4");
    MainWindow mainWin;
#if defined(Q_OS_SYMBIAN)
    mainWin.showMaximized();
#else
    mainWin.show();
#endif
    return app.exec();
}
