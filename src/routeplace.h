#ifndef ROUTEPLACE_H
#define ROUTEPLACE_H

#include <QtCore/QObject>

#include <qgeoplace.h>

class RouteMeAddress;
class RouteCoordinateItem;

using namespace QtMobility;

class RoutePlace : public QObject
{
    Q_OBJECT
    Q_PROPERTY(RouteMeAddress* address READ address WRITE setAddress NOTIFY addressChanged)
    Q_PROPERTY(RouteCoordinateItem* coordinate READ coordinate WRITE setCoordinate NOTIFY coordinateChanged)

public:
    RoutePlace(QObject *parent = 0);
    ~RoutePlace();

    RouteMeAddress* address();
    void setAddress(RouteMeAddress *address);

    RouteCoordinateItem* coordinate();
    void setCoordinate(RouteCoordinateItem *coordinate);

    void setGeoPlace(const QGeoPlace &place);

signals:
    void addressChanged();
    void coordinateChanged();

private:
    QGeoPlace m_place;

    RouteMeAddress *m_address;
    RouteCoordinateItem *m_coordinate;
};

#endif
