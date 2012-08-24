#ifndef ROUTEPOSITIONINFO_H
#define ROUTEPOSITIONINFO_H

#include <QtCore/QObject>

#include <qgeocoordinate.h>
#include <qgeopositioninfosource.h>

#include "routemecoordinate.h"

using namespace QtMobility;

class RoutePositionInfo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(RouteMeCoordinate* currentCoordinate READ currentCoordinate NOTIFY currentCoordinateAvailable)

public:
    RoutePositionInfo(QObject *parent = 0);
    ~RoutePositionInfo();

    RouteMeCoordinate* currentCoordinate();

    Q_INVOKABLE void startUpdates();
    Q_INVOKABLE void stopUpdates();

signals:
    void currentCoordinateAvailable();

private slots:
    void onPositionUpdated(const QGeoPositionInfo &info);

private:
    void init();

    QGeoPositionInfoSource *m_infoSourceSatellite;
    QGeoPositionInfoSource *m_infoSourceCellId;

    RouteMeCoordinate m_currentCoordinate;
};

#endif
