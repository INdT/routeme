#include "routegeomap.h"
#include "routemapitem.h"
#include "serviceprovider.h"

RouteMapItem::RouteMapItem(QDeclarativeItem *parent)
    : QDeclarativeItem(parent)
    , m_map(0)
    , m_mapManager(0)
    , m_zoomLevel(0)
    , m_coordinate(0)
    , m_route(0)
{
    init();
}

RouteMapItem::~RouteMapItem()
{
    m_mapManager->deleteLater();
}

void RouteMapItem::init()
{
    m_mapManager = ServiceProvider::instance()->mappingManager();
    m_map = new RouteGeoMap(m_mapManager, this);
}

RouteCoordinateItem* RouteMapItem::coordinate()
{
    return m_coordinate;
}

void RouteMapItem::setCoordinate(RouteCoordinateItem *coordinate)
{
    m_coordinate = coordinate;

    m_map->setCenterLatitude(m_coordinate->latitude());
    m_map->setCenterLongitude(m_coordinate->longitude());

    emit coordinateChanged();
}

void RouteMapItem::setZoomLevel(qreal zoom)
{
    if (zoom < 0)
        return;

    if (zoom == m_zoomLevel)
        return;

    m_zoomLevel = zoom;

    m_map->setZoomLevel(m_zoomLevel);
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
    m_map->setGeometry(0, 0, boundingRect().width(), boundingRect().height());
}

RouteMapObject* RouteMapItem::route()
{
    return m_route;
}

void RouteMapItem::setRoute(RouteMapObject *route)
{
    m_route = route;
    m_map->addMapObject(m_route->geoMapRouteObject());
    emit routeChanged();
}
