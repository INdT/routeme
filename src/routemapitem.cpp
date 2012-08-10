#include "routemapitem.h"
#include "routegeomap.h"

RouteMapItem::RouteMapItem(QDeclarativeItem *parent)
    : m_map(0)
    , m_serviceProvider(0)
    , m_mapManager(0)
    , m_latitude(0)
    , m_longitude(0)
{
    init();
}

void RouteMapItem::init()
{
    if (!m_providerName.isEmpty())
        m_serviceProvider = new QGeoServiceProvider(m_providerName);
    else
        m_serviceProvider = new QGeoServiceProvider("nokia");

    QGeoMappingManager *m_mapManager = m_serviceProvider->mappingManager();
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

void RouteMapItem::setProviderName(const QString &providerName)
{
    if (providerName.isEmpty())
        return;

    if (providerName == m_providerName)
        return;

    m_providerName = providerName;
    emit providerNameChanged();
}
