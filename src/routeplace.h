#ifndef ROUTEPLACE_H
#define ROUTEPLACE_H

#include <QtCore/QObject>

#include <qgeoplace.h>

class RouteMeAddress;
class RouteMeCoordinate;

using namespace QtMobility;

class RoutePlace : public QObject
{
    Q_OBJECT
    Q_PROPERTY(RouteMeAddress* address READ address WRITE setAddress NOTIFY addressChanged)
    Q_PROPERTY(RouteMeCoordinate* coordinate READ coordinate WRITE setCoordinate NOTIFY coordinateChanged)

public:
    RoutePlace(QObject *parent = 0);
    ~RoutePlace();

    RouteMeAddress* address();
    void setAddress(RouteMeAddress *address);

    RouteMeCoordinate* coordinate();
    void setCoordinate(RouteMeCoordinate *coordinate);

    void setGeoPlace(const QGeoPlace &place);

signals:
    void addressChanged();
    void coordinateChanged();

private:
    QGeoPlace m_place;

    RouteMeAddress *m_address;
    RouteMeCoordinate *m_coordinate;
};

#endif
