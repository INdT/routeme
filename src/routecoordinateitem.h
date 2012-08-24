#ifndef ROUTECOORDINATEITEM_H
#define ROUTECOORDINATEITEM_H

#include <QtCore/QObject>
#include <qgeocoordinate.h>

using namespace QtMobility;

class RouteCoordinateItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qreal latitude READ latitude WRITE setLatitude NOTIFY latitudeChanged)
    Q_PROPERTY(qreal longitude READ longitude WRITE setLongitude NOTIFY longitudeChanged)

public:
    RouteCoordinateItem(QObject *parent = 0);
    RouteCoordinateItem(const RouteCoordinateItem &coordinate, QObject *parent = 0);
    ~RouteCoordinateItem();

    qreal latitude() const { return m_coordinate.latitude(); }
    void setLatitude(qreal latitude);

    qreal longitude() const { return m_coordinate.longitude(); }
    void setLongitude(qreal longitude);

    void setGeoCoordinate(const QGeoCoordinate &coordinate);

signals:
    void latitudeChanged(qreal latitude);
    void longitudeChanged(qreal longitude);

private:
    QGeoCoordinate m_coordinate;
};
#endif
