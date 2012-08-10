#ifndef ROUTEMAPITEM_H
#define ROUTEMAPITEM_H

#include <QDeclarativeItem>
#include <QColor>

#include <qgeoserviceprovider.h>
#include <qgeomappingmanager.h>

class RouteGeoMap;

using namespace QtMobility;

class RouteMapItem : public QDeclarativeItem
{
    Q_OBJECT

    Q_PROPERTY(qreal latitude READ latitude WRITE setLatitude NOTIFY latitudeChanged)
    Q_PROPERTY(qreal longitude READ longitude WRITE setLongitude NOTIFY longitudeChanged)
    Q_PROPERTY(QString providerName READ providerName WRITE setProviderName NOTIFY providerNameChanged)

public:
    RouteMapItem(QDeclarativeItem *parent = 0);

    qreal latitude() const { return m_latitude; }
    void setLatitude(qreal latitude);

    qreal longitude() const { return m_longitude; }
    void setLongitude(qreal longitude);

    QString providerName() const { return m_providerName; }
    void setProviderName(const QString &providerName);

signals:
    void latitudeChanged();
    void longitudeChanged();
    void providerNameChanged();

private:
    void init();

    RouteGeoMap *m_map;
    QGeoServiceProvider *m_serviceProvider;
    QGeoMappingManager *m_mapManager;

    qreal m_latitude;
    qreal m_longitude;
    QString m_providerName;
};

#endif
