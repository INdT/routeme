#include "routemeroutemapobject.h"

RouteMeRouteMapObject::RouteMeRouteMapObject(QObject *parent)
    : QObject(parent)
    , m_routeObject(0)
{
}

RouteMeRouteMapObject::~RouteMeRouteMapObject()
{
    if (m_routeObject)
        m_routeObject->deleteLater();
}

void RouteMeRouteMapObject::setGeoMapRouteObject(QGeoMapRouteObject *route)
{
    m_routeObject = route;
}

QGeoMapRouteObject* RouteMeRouteMapObject::geoMapRouteObject()
{
    return m_routeObject;
}
