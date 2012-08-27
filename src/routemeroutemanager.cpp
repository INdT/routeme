#include "routemeroutemanager.h"
#include "serviceprovider.h"

#include <qgeorouterequest.h>
#include <qgeoroutereply.h>

#include <QPen>
#include <QBrush>

RouteMeRouteManager::RouteMeRouteManager(QObject *parent)
    : QObject(parent)
    , m_routingManager(0)
    , m_origin(0)
    , m_destination(0)
    , m_routeObject(0)
{
    init();
}

RouteMeRouteManager::~RouteMeRouteManager()
{
    m_routingManager->deleteLater();
    m_origin->deleteLater();
    m_destination->deleteLater();
    m_routeObject->deleteLater();
}

void RouteMeRouteManager::init()
{
    m_routingManager = ServiceProvider::instance()->routingManager();
    connect(m_routingManager, SIGNAL(finished(QGeoRouteReply *)),
            this, SLOT(onCalculateRouteFinished(QGeoRouteReply *)));
}

RouteMeCoordinate* RouteMeRouteManager::origin()
{
    return m_origin;
}

void RouteMeRouteManager::setOrigin(RouteMeCoordinate *origin)
{
    m_origin = origin;
    emit originChanged();
}

RouteMeCoordinate* RouteMeRouteManager::destination()
{
    return m_destination;
}

void RouteMeRouteManager::setDestination(RouteMeCoordinate *destination)
{
    m_destination = destination;
    emit destinationChanged();
}

void RouteMeRouteManager::calculateRoute()
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

void RouteMeRouteManager::onCalculateRouteFinished(QGeoRouteReply *reply)
{
    if (!reply)
        return;

    if (!reply->routes().isEmpty()) {
        QGeoRoute route = reply->routes().at(0);
        QGeoMapRouteObject *routeObject = new QGeoMapRouteObject(route);

        QPen pen;
        pen.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
        pen.setWidth(3);
        routeObject->setPen(pen);

        routeObject->setDetailLevel(8);

        m_routeObject = new RouteMapObject;
        m_routeObject->setGeoMapRouteObject(routeObject);
        emit routeAvailable();
    }

    reply->deleteLater();
}

RouteMapObject* RouteMeRouteManager::route()
{
    return m_routeObject;
}
