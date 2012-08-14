#ifndef ROUTEMAPITEM_H
#define ROUTEMAPITEM_H

#include <QDeclarativeItem>
#include <QColor>

#include <qgeoserviceprovider.h>
#include <qgeomappingmanager.h>
#include <qgeocoordinate.h>

class RouteGeoMap;
class RoutePositionInfo;

using namespace QtMobility;

class RouteMapItem : public QDeclarativeItem
{
    Q_OBJECT

    Q_PROPERTY(qreal latitude READ latitude WRITE setLatitude NOTIFY latitudeChanged)
    Q_PROPERTY(qreal longitude READ longitude WRITE setLongitude NOTIFY longitudeChanged)
    Q_PROPERTY(qreal zoomLevel READ zoomLevel WRITE setZoomLevel NOTIFY zoomLevelChanged)
    Q_PROPERTY(QString providerName READ providerName WRITE setProviderName NOTIFY providerNameChanged)

public:
    RouteMapItem(QDeclarativeItem *parent = 0);
    ~RouteMapItem();

    qreal latitude() const { return m_latitude; }
    void setLatitude(qreal latitude);

    qreal longitude() const { return m_longitude; }
    void setLongitude(qreal longitude);

    qreal zoomLevel() const { return m_zoomLevel; }
    void setZoomLevel(qreal zoom);

    QString providerName() const { return m_providerName; }
    void setProviderName(const QString &providerName);

    void componentComplete();
    void classBegin();

signals:
    void latitudeChanged();
    void longitudeChanged();
    void providerNameChanged();
    void zoomLevelChanged();

private slots:
    void onCurrentCoordinateAvailable(const QGeoCoordinate &coordinate);

private:
    void init();

    RouteGeoMap *m_map;
    QGeoMappingManager *m_mapManager;
    RoutePositionInfo *m_positionInfo;

    qreal m_latitude;
    qreal m_longitude;
    qreal m_zoomLevel;
    QString m_providerName;
    QGeoCoordinate m_coordinate;
};

#endif
