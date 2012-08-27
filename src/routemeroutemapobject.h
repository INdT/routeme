#ifndef ROUTEMEROUTEMAPOBJECT_H
#define ROUTEMEROUTEMAPOBJECT_H

#include <QtCore/QObject>

#include <qgeomaprouteobject.h>

using namespace QtMobility;

class RouteMeRouteMapObject : public QObject
{
    Q_OBJECT

public:
    RouteMeRouteMapObject(QObject *parent = 0);
    ~RouteMeRouteMapObject();

    void setGeoMapRouteObject(QGeoMapRouteObject *route);
    QGeoMapRouteObject* geoMapRouteObject();

private:
    QGeoMapRouteObject *m_routeObject;
};

#endif
