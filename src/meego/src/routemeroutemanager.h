#ifndef ROUTEMEROUTEMANAGER_H
#define ROUTEMEROUTEMANAGER_H

#include <QtCore/QObject>

#include <qgeoroutingmanager.h>
#include <qgeoroutereply.h>

#include "routemecoordinate.h"
#include "routemeroutemapobject.h"

using namespace QtMobility;

class RouteMeRouteManager : public QObject
{
    Q_OBJECT

    Q_PROPERTY(RouteMeCoordinate* origin READ origin WRITE setOrigin NOTIFY originChanged)
    Q_PROPERTY(RouteMeCoordinate* destination READ destination WRITE setDestination NOTIFY destinationChanged)
    Q_PROPERTY(RouteMeRouteMapObject* route READ route NOTIFY routeAvailable)

public:
    RouteMeRouteManager(QObject *parent = 0);
    ~RouteMeRouteManager();

    RouteMeCoordinate* origin();
    void setOrigin(RouteMeCoordinate *origin);

    RouteMeCoordinate* destination();
    void setDestination(RouteMeCoordinate *destination);

    RouteMeRouteMapObject* route();


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
    RouteMeRouteMapObject *m_routeObject;
};

#endif
