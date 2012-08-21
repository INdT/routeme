#ifndef ROUTEMAPOBJECT_H
#define ROUTEMAPOBJECT_H

#include <QtCore/QObject>

#include <qgeomaprouteobject.h>

using namespace QtMobility;

class RouteMapObject : public QObject
{
    Q_OBJECT

public:
    RouteMapObject(QObject *parent = 0);
    ~RouteMapObject();

    void setGeoMapRouteObject(QGeoMapRouteObject *route);

private:
    QGeoMapRouteObject *m_routeObject;
};

#endif
