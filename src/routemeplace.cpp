#include "routemeplace.h"
#include "routemecoordinate.h"
#include "routemeaddress.h"

RouteMePlace::RouteMePlace(QObject *parent)
    : QObject(parent)
    , m_address(0)
    , m_coordinate(0)
{
}

RouteMePlace::~RouteMePlace()
{
}

RouteMeCoordinate* RouteMePlace::coordinate()
{
    return m_coordinate;
}

void RouteMePlace::setCoordinate(RouteMeCoordinate *coordinate)
{
    m_coordinate = coordinate;
    emit coordinateChanged();
}

RouteMeAddress* RouteMePlace::address()
{
    return m_address;
}

void RouteMePlace::setAddress(RouteMeAddress* address)
{
    m_address = address;
    emit addressChanged();
}

void RouteMePlace::setGeoPlace(const QGeoPlace &place)
{
    m_place = place;
    m_address = new RouteMeAddress;
    m_address->setGeoAddress(place.address());
}
