#include "routemesearchmanager.h"
#include "serviceprovider.h"
#include "routemecoordinate.h"
#include "routemeplace.h"

RouteMeSearchManager::RouteMeSearchManager(QObject *parent)
    : QObject(parent)
    , m_searchManager(0)
    , m_coordinate(0)
    , m_place(0)
{
    init();
}

RouteMeSearchManager::~RouteMeSearchManager()
{
}

void RouteMeSearchManager::init()
{
    m_searchManager = ServiceProvider::instance()->searchManager();
}

RouteMeCoordinate* RouteMeSearchManager::coordinate()
{
    return m_coordinate;
}

void RouteMeSearchManager::setCoordinate(RouteMeCoordinate* coordinate)
{
    m_coordinate = coordinate;

    emit coordinateChanged();
}

void RouteMeSearchManager::searchPlace()
{
    if (!m_searchManager)
        return;

    if (!m_coordinate)
        return;

    QGeoCoordinate coord;
    coord.setLatitude(m_coordinate->latitude());
    coord.setLongitude(m_coordinate->longitude());

    QGeoSearchReply *reply = m_searchManager->reverseGeocode(coord);
    connect(reply, SIGNAL(finished()), this, SLOT(onReverseGeocodeFinished()));
}

void RouteMeSearchManager::onReverseGeocodeFinished()
{
    QGeoSearchReply *reply = qobject_cast<QGeoSearchReply *>(sender());

    QList<QGeoPlace> places;
    if (reply)
        places = reply->places();

    if (!places.isEmpty()) {
        m_place = new RouteMePlace;
        m_place->setCoordinate(m_coordinate);
        m_place->setGeoPlace(places.at(0));
    }

    emit placeAvailable();
    reply->deleteLater();
}

RouteMePlace* RouteMeSearchManager::place()
{
    return m_place;
}
