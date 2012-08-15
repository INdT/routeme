#include "routepositioninfo.h"
#include "serviceprovider.h"

RoutePositionInfo::RoutePositionInfo(QObject *parent)
    : QObject(parent)
    , m_searchManager(0)
    , m_infoSourceSatellite(0)
    , m_infoSourceCellId(0)
{
    init();
}

RoutePositionInfo::~RoutePositionInfo()
{
}

void RoutePositionInfo::init()
{
    m_searchManager = ServiceProvider::instance()->searchManager();

    m_infoSourceSatellite = QGeoPositionInfoSource::createDefaultSource(this);
    if (m_infoSourceSatellite) {
        m_infoSourceSatellite->setPreferredPositioningMethods(QGeoPositionInfoSource::SatellitePositioningMethods);
        connect(m_infoSourceSatellite, SIGNAL(positionUpdated(const QGeoPositionInfo &)),
            this, SLOT(onPositionUpdated(const QGeoPositionInfo &)));
    }

    m_infoSourceCellId = QGeoPositionInfoSource::createDefaultSource(this);
    if (m_infoSourceCellId) {
        m_infoSourceCellId->setPreferredPositioningMethods(QGeoPositionInfoSource::NonSatellitePositioningMethods);
        connect(m_infoSourceCellId, SIGNAL(positionUpdated(const QGeoPositionInfo &)),
            this, SLOT(onPositionUpdated(const QGeoPositionInfo &)));
    }

}

void RoutePositionInfo::onPositionUpdated(const QGeoPositionInfo &info)
{
    if (!info.isValid() || !info.coordinate().isValid())
        return;

    emit currentCoordinateAvailable(info.coordinate());

    stopUpdates();
}

void RoutePositionInfo::startUpdates()
{
    if (!m_infoSourceSatellite || !m_infoSourceCellId)
        return;

    m_infoSourceSatellite->startUpdates();
    m_infoSourceCellId->startUpdates();
}

void RoutePositionInfo::stopUpdates()
{
    if (!m_infoSourceSatellite || !m_infoSourceCellId)
        return;

    m_infoSourceSatellite->stopUpdates();
    m_infoSourceCellId->stopUpdates();
}

void RoutePositionInfo::coordinateToPlace(const QGeoCoordinate &coordinate)
{
    if (!m_searchManager)
        return;

    if (!coordinate.isValid())
        return;

    QGeoSearchReply *reply = m_searchManager->reverseGeocode(coordinate);
    connect(reply, SIGNAL(finished()), this, SLOT(onReverseGeocodeFinished()));
    connect(reply, SIGNAL(error(QGeoSearchReply::Error, const QString &)),
            this, SIGNAL(searchReplyError(QGeoSearchReply::Error, const QString &)));
}

void RoutePositionInfo::onReverseGeocodeFinished()
{
    QGeoSearchReply *reply = qobject_cast<QGeoSearchReply *>(sender());

    QList<QGeoPlace> places;
    if (reply) {
        places = reply->places();
    }

    emit coordinateToPlaceAvailable(places);

    reply->deleteLater();
}
