#ifndef ROUTEMAPITEM_H
#define ROUTEMAPITEM_H

#include <QDeclarativeItem>

#include <qgeoserviceprovider.h>
#include <qgeomappingmanager.h>
#include <qgeocoordinate.h>

#include "routecoordinateitem.h"

class RouteGeoMap;

using namespace QtMobility;

class RouteMapItem : public QDeclarativeItem
{
    Q_OBJECT

    Q_PROPERTY(RouteCoordinateItem* coordinate READ coordinate WRITE setCoordinate NOTIFY coordinateChanged)
    Q_PROPERTY(qreal zoomLevel READ zoomLevel WRITE setZoomLevel NOTIFY zoomLevelChanged)
    Q_PROPERTY(QString providerName READ providerName WRITE setProviderName NOTIFY providerNameChanged)

public:
    RouteMapItem(QDeclarativeItem *parent = 0);
    ~RouteMapItem();

    RouteCoordinateItem* coordinate();
    void setCoordinate(RouteCoordinateItem *coordinate);

    qreal zoomLevel() const { return m_zoomLevel; }
    void setZoomLevel(qreal zoom);

    QString providerName() const { return m_providerName; }
    void setProviderName(const QString &providerName);

    void componentComplete();

signals:
    void coordinateChanged();
    void providerNameChanged();
    void zoomLevelChanged();

private:
    void init();

    RouteGeoMap *m_map;
    QGeoMappingManager *m_mapManager;
    qreal m_zoomLevel;
    QString m_providerName;
    RouteCoordinateItem *m_coordinate;
};

#endif
