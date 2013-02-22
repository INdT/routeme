#include <QtGui/QApplication>

#include "routeme.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("RouteMe");
    app.setOrganizationName("INdT");

    RouteMe routeme;

#if defined(MEEGO_EDITION_HARMATTAN)
    routeme.showFullScreen();
#else
    routeme.setGeometry(0, 0, 480, 864);
    routeme.show();
#endif

    return app.exec();
}
