#ifndef ROUTEGEOMAP_H
#define ROUTEGEOMAP_H

#include "qgraphicsgeomap.h"

using namespace QtMobility;

class RouteGeoMap : public QGraphicsGeoMap
{
    Q_OBJECT
    Q_PROPERTY(double centerLatitude READ centerLatitude WRITE setCenterLatitude)
    Q_PROPERTY(double centerLongitude READ centerLongitude WRITE setCenterLongitude)

public:
    RouteGeoMap(QGeoMappingManager *manager, QGraphicsItem *parent = 0);
    ~RouteGeoMap();

    double centerLatitude() const;
    void setCenterLatitude(double latitude);
    double centerLongitude() const;
    void setCenterLongitude(double longitude);

private:
    bool panActive;
    bool markerPressed;
    QGeoMapObject *pressed;

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void wheelEvent(QGraphicsSceneWheelEvent *event);
    void keyPressEvent(QKeyEvent *event);

signals:
    void clicked(QGeoMapObject *marker);
    void panned();
};
#endif
