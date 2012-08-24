#ifndef ROUTEMAPITEM_H
#define ROUTEMAPITEM_H

#include <QtDeclarative/QDeclarativeItem>

#include <qgeoserviceprovider.h>
#include <qgeomappingmanager.h>
#include <qgeocoordinate.h>

#include "routecoordinateitem.h"
#include "routemapobject.h"

class RouteGeoMap;

using namespace QtMobility;

class RouteMapItem : public QDeclarativeItem
{
    Q_OBJECT

    Q_PROPERTY(RouteCoordinateItem* coordinate READ coordinate WRITE setCoordinate NOTIFY coordinateChanged)
    Q_PROPERTY(qreal zoomLevel READ zoomLevel WRITE setZoomLevel NOTIFY zoomLevelChanged)
    Q_PROPERTY(QString providerName READ providerName WRITE setProviderName NOTIFY providerNameChanged)
    Q_PROPERTY(RouteMapObject* route READ route WRITE setRoute NOTIFY routeChanged)

public:
    RouteMapItem(QDeclarativeItem *parent = 0);
    ~RouteMapItem();

    RouteCoordinateItem* coordinate();
    void setCoordinate(RouteCoordinateItem *coordinate);

    qreal zoomLevel() const { return m_zoomLevel; }
    void setZoomLevel(qreal zoom);

    QString providerName() const { return m_providerName; }
    void setProviderName(const QString &providerName);

    RouteMapObject* route();
    void setRoute(RouteMapObject* route);

    void componentComplete();

signals:
    void coordinateChanged();
    void providerNameChanged();
    void zoomLevelChanged();
    void routeChanged();

private:
    void init();

    RouteGeoMap *m_map;
    QGeoMappingManager *m_mapManager;
    qreal m_zoomLevel;
    QString m_providerName;
    RouteCoordinateItem *m_coordinate;
    RouteMapObject *m_route;
};

#endif
