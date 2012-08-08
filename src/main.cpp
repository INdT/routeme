#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("RouteMe");
    app.setOrganizationName("INdT");

    return app.exec();
}
