#ifndef ROUTEMECONTROLLER_H
#define ROUTEMECONTROLLER_H

#include <QtCore/QObject>

class RouteMeServer;

class RouteMeController : public QObject
{
    Q_OBJECT
public:
    RouteMeController(QObject *parent = 0);
    ~RouteMeController();

    void init();

private:
    RouteMeServer *m_server;
};

#endif
