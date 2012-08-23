#ifndef ROUTEPLACE_H
#define ROUTEPLACE_H

#include <QtCore/QObject>

#include <qgeoplace.h>

class RouteAddress;
class RouteCoordinateItem;

using namespace QtMobility;

class RoutePlace : public QObject
{
    Q_OBJECT
    Q_PROPERTY(RouteAddress* address READ address WRITE setAddress NOTIFY addressChanged)
    Q_PROPERTY(RouteCoordinateItem* coordinate READ coordinate WRITE setCoordinate NOTIFY coordinateChanged)

public:
    RoutePlace(QObject *parent = 0);
    ~RoutePlace();

    RouteAddress* address();
    void setAddress(RouteAddress *address);

    RouteCoordinateItem* coordinate();
    void setCoordinate(RouteCoordinateItem *coordinate);

    void setGeoPlace(const QGeoPlace &place);

signals:
    void addressChanged();
    void coordinateChanged();

private:
    QGeoPlace m_place;

    RouteAddress *m_address;
    RouteCoordinateItem *m_coordinate;
};

#endif
