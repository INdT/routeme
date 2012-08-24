#include "routeplace.h"
#include "routemecoordinate.h"
#include "routemeaddress.h"

RoutePlace::RoutePlace(QObject *parent)
    : QObject(parent)
    , m_address(0)
    , m_coordinate(0)
{
}

RoutePlace::~RoutePlace()
{
}

RouteMeCoordinate* RoutePlace::coordinate()
{
    return m_coordinate;
}

void RoutePlace::setCoordinate(RouteMeCoordinate *coordinate)
{
    m_coordinate = coordinate;
    emit coordinateChanged();
}

RouteMeAddress* RoutePlace::address()
{
    return m_address;
}

void RoutePlace::setAddress(RouteMeAddress* address)
{
    m_address = address;
    emit addressChanged();
}

void RoutePlace::setGeoPlace(const QGeoPlace &place)
{
    m_place = place;
    m_address = new RouteMeAddress;
    m_address->setGeoAddress(place.address());
}
