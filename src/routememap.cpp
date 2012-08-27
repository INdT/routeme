#include "routemegraphicsgeomap.h"
#include "routememap.h"
#include "serviceprovider.h"

RouteMeMap::RouteMeMap(QDeclarativeItem *parent)
    : QDeclarativeItem(parent)
    , m_map(0)
    , m_mapManager(0)
    , m_zoomLevel(0)
    , m_coordinate(0)
    , m_route(0)
{
    init();
}

RouteMeMap::~RouteMeMap()
{
    m_mapManager->deleteLater();
}

void RouteMeMap::init()
{
    m_mapManager = ServiceProvider::instance()->mappingManager();
    m_map = new RouteMeGraphicsGeoMap(m_mapManager, this);
}

RouteMeCoordinate* RouteMeMap::coordinate()
{
    return m_coordinate;
}

void RouteMeMap::setCoordinate(RouteMeCoordinate *coordinate)
{
    m_coordinate = coordinate;

    m_map->setCenterLatitude(m_coordinate->latitude());
    m_map->setCenterLongitude(m_coordinate->longitude());

    emit coordinateChanged();
}

void RouteMeMap::setZoomLevel(qreal zoom)
{
    if (zoom < 0)
        return;

    if (zoom == m_zoomLevel)
        return;

    m_zoomLevel = zoom;

    m_map->setZoomLevel(m_zoomLevel);
    emit zoomLevelChanged();
}

void RouteMeMap::setProviderName(const QString &providerName)
{
    if (providerName.isEmpty())
        return;

    if (providerName == m_providerName)
        return;

    m_providerName = providerName;
    emit providerNameChanged();
}

void RouteMeMap::componentComplete()
{
    m_map->setGeometry(0, 0, boundingRect().width(), boundingRect().height());
}

RouteMapObject* RouteMeMap::route()
{
    return m_route;
}

void RouteMeMap::setRoute(RouteMapObject *route)
{
    m_route = route;
    m_map->addMapObject(m_route->geoMapRouteObject());
    emit routeChanged();
}
