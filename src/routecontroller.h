#ifndef ROUTECONTROLLER_H
#define ROUTECONTROLLER_H

#include <QtCore/QObject>

class RouteMeServer;

class RouteController : public QObject
{
    Q_OBJECT
public:
    RouteController(QObject *parent = 0);
    ~RouteController();

    void init();

private:
    RouteMeServer *m_server;
};

#endif
