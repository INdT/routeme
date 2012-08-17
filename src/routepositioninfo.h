#ifndef ROUTEPOSITIONINFO_H
#define ROUTEPOSITIONINFO_H

#include <QObject>

#include <qgeoplace.h>
#include <qgeocoordinate.h>
#include <qgeosearchmanager.h>
#include <qgeopositioninfosource.h>

#include "routecoordinateitem.h"

using namespace QtMobility;

class RoutePositionInfo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(RouteCoordinateItem* currentCoordinate READ currentCoordinate NOTIFY currentCoordinateAvailable)

public:
    RoutePositionInfo(QObject *parent = 0);
    ~RoutePositionInfo();

    RouteCoordinateItem* currentCoordinate();

    void coordinateToPlace(const QGeoCoordinate &coordinate);
    Q_INVOKABLE void startUpdates();
    Q_INVOKABLE void stopUpdates();

signals:
    void currentCoordinateAvailable();
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

    RouteCoordinateItem m_currentCoordinate;
};

#endif
