#include "routemapobject.h"

RouteMapObject::RouteMapObject(QObject *parent)
    : QObject(parent)
    , m_routeObject(0)
{
}

RouteMapObject::~RouteMapObject()
{
    if (m_routeObject)
        m_routeObject->deleteLater();
}

void RouteMapObject::setGeoMapRouteObject(QGeoMapRouteObject *route)
{
    m_routeObject = route;
}
