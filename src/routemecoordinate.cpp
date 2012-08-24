#include "routemecoordinate.h"

RouteMeCoordinate::RouteMeCoordinate(QObject *parent)
    : QObject(parent)
{
}

RouteMeCoordinate::RouteMeCoordinate(const RouteMeCoordinate &coordinate, QObject *parent)
    : QObject(parent)
    , m_coordinate(coordinate.m_coordinate)
{
}

RouteMeCoordinate::~RouteMeCoordinate()
{
}

void RouteMeCoordinate::setLatitude(qreal latitude)
{
    m_coordinate.setLatitude(latitude);
    emit latitudeChanged(latitude);
}

void RouteMeCoordinate::setLongitude(qreal longitude)
{
    m_coordinate.setLongitude(longitude);
    emit longitudeChanged(longitude);
}

void RouteMeCoordinate::setGeoCoordinate(const QGeoCoordinate &coordinate)
{
    m_coordinate = coordinate;
    setLatitude(m_coordinate.latitude());
    setLongitude(m_coordinate.longitude());
}
