#ifndef ROUTEMEMAP_H
#define ROUTEMEMAP_H

#include <QtDeclarative/QDeclarativeItem>

#include <qgeoserviceprovider.h>
#include <qgeomappingmanager.h>
#include <qgeocoordinate.h>

#include "routemecoordinate.h"
#include "routemeroutemapobject.h"
#include "routemepixmapobject.h"

class RouteMeGraphicsGeoMap;

using namespace QtMobility;

class RouteMeMap : public QDeclarativeItem
{
    Q_OBJECT

    Q_PROPERTY(RouteMeCoordinate* coordinate READ coordinate WRITE setCoordinate NOTIFY coordinateChanged)
    Q_PROPERTY(qreal zoomLevel READ zoomLevel WRITE setZoomLevel NOTIFY zoomLevelChanged)
    Q_PROPERTY(QString providerName READ providerName WRITE setProviderName NOTIFY providerNameChanged)
    Q_PROPERTY(RouteMeRouteMapObject* route READ route WRITE setRoute NOTIFY routeChanged)
    Q_PROPERTY(RouteMePixmapObject* currentPixmapLocation READ currentPixmapLocation WRITE setCurrentPixmapLocation NOTIFY currentPixmapLocationChanged)

public:
    RouteMeMap(QDeclarativeItem *parent = 0);
    ~RouteMeMap();

    RouteMeCoordinate* coordinate();
    void setCoordinate(RouteMeCoordinate *coordinate);

    qreal zoomLevel() const { return m_zoomLevel; }
    void setZoomLevel(qreal zoom);

    QString providerName() const { return m_providerName; }
    void setProviderName(const QString &providerName);

    RouteMeRouteMapObject* route();
    void setRoute(RouteMeRouteMapObject* route);

    RouteMePixmapObject* currentPixmapLocation() { return m_currentPixmapLocation; }
    void setCurrentPixmapLocation(RouteMePixmapObject *pixmap);

    void componentComplete();

signals:
    void coordinateChanged();
    void providerNameChanged();
    void zoomLevelChanged();
    void routeChanged();
    void currentPixmapLocationChanged();

private:
    void init();

    RouteMeGraphicsGeoMap *m_map;
    QGeoMappingManager *m_mapManager;
    qreal m_zoomLevel;
    QString m_providerName;
    RouteMeCoordinate *m_coordinate;
    RouteMeRouteMapObject *m_route;
    RouteMePixmapObject *m_currentPixmapLocation;
};

#endif
