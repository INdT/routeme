#ifndef ROUTEMEGRAPHICSGEOMAP_H
#define ROUTEMEGRAPHICSGEOMAP_H

#include "qgraphicsgeomap.h"

using namespace QtMobility;

class RouteMeGraphicsGeoMap : public QGraphicsGeoMap
{
    Q_OBJECT
    Q_PROPERTY(double centerLatitude READ centerLatitude WRITE setCenterLatitude)
    Q_PROPERTY(double centerLongitude READ centerLongitude WRITE setCenterLongitude)

public:
    RouteMeGraphicsGeoMap(QGeoMappingManager *manager, QGraphicsItem *parent = 0);
    ~RouteMeGraphicsGeoMap();

    double centerLatitude() const;
    double centerLongitude() const;

public slots:
    void setCenterLatitude(qreal latitude);
    void setCenterLongitude(qreal longitude);

signals:
    void clicked(QGeoMapObject *marker);
    void panned();

private:
    bool panActive;
    bool markerPressed;
    QGeoMapObject *objectPressed;

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void wheelEvent(QGraphicsSceneWheelEvent *event);
    void keyPressEvent(QKeyEvent *event);
};
#endif
