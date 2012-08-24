#ifndef ROUTINGMANAGER_H
#define ROUTINGMANAGER_H

#include <QtCore/QObject>

#include <qgeoroutingmanager.h>
#include <qgeoroutereply.h>

#include "routemecoordinate.h"
#include "routemapobject.h"

using namespace QtMobility;

class RoutingManager : public QObject
{
    Q_OBJECT

    Q_PROPERTY(RouteMeCoordinate* origin READ origin WRITE setOrigin NOTIFY originChanged)
    Q_PROPERTY(RouteMeCoordinate* destination READ destination WRITE setDestination NOTIFY destinationChanged)
    Q_PROPERTY(RouteMapObject* route READ route NOTIFY routeAvailable)

public:
    RoutingManager(QObject *parent = 0);
    ~RoutingManager();

    RouteMeCoordinate* origin();
    void setOrigin(RouteMeCoordinate *origin);

    RouteMeCoordinate* destination();
    void setDestination(RouteMeCoordinate *destination);

    RouteMapObject* route();


    Q_INVOKABLE void calculateRoute();

signals:
    void originChanged();
    void destinationChanged();
    void routeAvailable();

private slots:
    void onCalculateRouteFinished(QGeoRouteReply *reply);

private:
    void init();

    QGeoRoutingManager *m_routingManager;

    RouteMeCoordinate *m_origin;
    RouteMeCoordinate *m_destination;
    RouteMapObject *m_routeObject;
};

#endif
