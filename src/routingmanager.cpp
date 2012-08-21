#include "routingmanager.h"
#include "serviceprovider.h"

#include <qgeorouterequest.h>
#include <qgeoroutereply.h>

RoutingManager::RoutingManager(QObject *parent)
    : QObject(parent)
    , m_routingManager(0)
    , m_origin(0)
    , m_destination(0)
    , m_routeObject(0)
{
    init();
}

RoutingManager::~RoutingManager()
{
    m_routingManager->deleteLater();
    m_origin->deleteLater();
    m_destination->deleteLater();
    m_routeObject->deleteLater();
}

void RoutingManager::init()
{
    m_routingManager = ServiceProvider::instance()->routingManager();
    connect(m_routingManager, SIGNAL(finished(QGeoRouteReply *)),
            this, SLOT(onCalculateRouteFinished(QGeoRouteReply *)));
}

RouteCoordinateItem* RoutingManager::origin()
{
    return m_origin;
}

void RoutingManager::setOrigin(RouteCoordinateItem *origin)
{
    m_origin = origin;
    emit originChanged();
}

RouteCoordinateItem* RoutingManager::destination()
{
    return m_destination;
}

void RoutingManager::setDestination(RouteCoordinateItem *destination)
{
    m_destination = destination;
    emit destinationChanged();
}

void RoutingManager::calculateRoute()
{
    if (!m_origin || !m_destination)
        return;

    QGeoCoordinate origin;
    origin.setLatitude(m_origin->latitude());
    origin.setLongitude(m_origin->longitude());

    QGeoCoordinate destination;
    destination.setLatitude(m_destination->latitude());
    destination.setLongitude(m_destination->longitude());

    QGeoRouteRequest routeRequest(origin, destination);
    routeRequest.setTravelModes(QGeoRouteRequest::CarTravel);
    routeRequest.setRouteOptimization(QGeoRouteRequest::ShortestRoute);

    m_routingManager->calculateRoute(routeRequest);
}

void RoutingManager::onCalculateRouteFinished(QGeoRouteReply *reply)
{
    if (!reply)
        return;

    if (!reply->routes().isEmpty()) {
        QGeoRoute route = reply->routes().at(0);
        QGeoMapRouteObject *routeObject = new QGeoMapRouteObject(route);
        m_routeObject = new RouteMapObject;
        m_routeObject->setGeoMapRouteObject(routeObject);
        emit routeAvailable();
    }

    reply->deleteLater();
}

RouteMapObject* RoutingManager::route()
{
    return m_routeObject;
}
