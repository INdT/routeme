#ifndef ROUTEPOSITIONINFO_H
#define ROUTEPOSITIONINFO_H

#include <QObject>

#include <qgeoplace.h>
#include <qgeocoordinate.h>
#include <qgeosearchmanager.h>
#include <qgeopositioninfosource.h>

using namespace QtMobility;

class RoutePositionInfo : public QObject
{
    Q_OBJECT

public:
    RoutePositionInfo(QObject *parent = 0);
    ~RoutePositionInfo();

    void coordinateToPlace(const QGeoCoordinate &coordinate);
    void currentCoordinate();

signals:
    void currentCoordinateAvailable(const QGeoCoordinate &coordinate);
    void coordinateToPlaceAvailable(const QList<QGeoPlace> &places);
    void searchReplyError(QGeoSearchReply::Error error, const QString &errorString);

private slots:
    void onPositionUpdated(const QGeoPositionInfo &info);
    void onReverseGeocodeFinished();

private:
    void init();

    QGeoSearchManager *m_searchManager;
    QGeoPositionInfoSource *m_infoSourceSatellite;
    QGeoPositionInfoSource *m_infoSourceCellId;
};

#endif
