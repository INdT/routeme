#include "routecoordinateitem.h"

RouteCoordinateItem::RouteCoordinateItem(QObject *parent)
    : QObject(parent)
{
}

RouteCoordinateItem::RouteCoordinateItem(const RouteCoordinateItem &coordinate, QObject *parent)
    : QObject(parent)
    , m_coordinate(coordinate.m_coordinate)
{
}

RouteCoordinateItem::~RouteCoordinateItem()
{
}

void RouteCoordinateItem::setLatitude(qreal latitude)
{
    m_coordinate.setLatitude(latitude);
    emit latitudeChanged(latitude);
}

void RouteCoordinateItem::setLongitude(qreal longitude)
{
    m_coordinate.setLongitude(longitude);
    emit longitudeChanged(longitude);
}

void RouteCoordinateItem::setGeoCoordinate(const QGeoCoordinate &coordinate)
{
    m_coordinate = coordinate;
    setLatitude(m_coordinate.latitude());
    setLongitude(m_coordinate.longitude());
}
