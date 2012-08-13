#include "routemapitem.h"
#include "routegeomap.h"
#include "serviceprovider.h"

RouteMapItem::RouteMapItem(QDeclarativeItem *parent)
    : QDeclarativeItem(parent)
    , m_map(0)
    , m_mapManager(0)
    , m_latitude(0)
    , m_longitude(0)
    , m_zoomLevel(0)
{
    init();
}

void RouteMapItem::init()
{
    m_mapManager = ServiceProvider::instance()->mappingManager();
    m_map = new RouteGeoMap(m_mapManager, this);
}

void RouteMapItem::setLatitude(qreal latitude)
{
    if (latitude == m_latitude)
        return;

    m_latitude = latitude;

    emit latitudeChanged();

    update();
}

void RouteMapItem::setLongitude(qreal longitude)
{
    if (longitude == m_longitude)
        return;

    m_longitude = longitude;
    emit longitudeChanged();
    update();
}

void RouteMapItem::setZoomLevel(qreal zoom)
{
    if (zoom < 0)
        return;

    if (zoom == m_zoomLevel)
        return;

    m_zoomLevel = zoom;

    emit zoomLevelChanged();
}

void RouteMapItem::setProviderName(const QString &providerName)
{
    if (providerName.isEmpty())
        return;

    if (providerName == m_providerName)
        return;

    m_providerName = providerName;
    emit providerNameChanged();
}

void RouteMapItem::componentComplete()
{
    if (m_latitude == 0 && m_longitude == 0)
        return;

    m_coordinate.setLatitude(m_latitude);
    m_coordinate.setLongitude(m_longitude);
    m_coordinate.setAltitude(0.0);

    m_map->setCenterLatitude(m_latitude);
    m_map->setCenterLongitude(m_longitude);
    m_map->setZoomLevel(5.0);
    m_map->setCenter(m_coordinate);

    m_map->setGeometry(0, 0, boundingRect().width(), boundingRect().height());
}
