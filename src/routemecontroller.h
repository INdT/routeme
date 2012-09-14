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

    Q_INVOKABLE void sendMyCurrentLocation(const QString &number, const QString &message);
    Q_INVOKABLE bool isContactsAvailable();

private:
    RouteMeServer *m_server;
};

#endif
