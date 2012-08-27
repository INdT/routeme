#ifndef ROUTEMEPOSITIONINFO_H
#define ROUTEMEPOSITIONINFO_H

#include <QtCore/QObject>

#include <qgeocoordinate.h>
#include <qgeopositioninfosource.h>

#include "routemecoordinate.h"

using namespace QtMobility;

class RouteMePositionInfo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(RouteMeCoordinate* currentCoordinate READ currentCoordinate NOTIFY currentCoordinateAvailable)

public:
    RouteMePositionInfo(QObject *parent = 0);
    ~RouteMePositionInfo();

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
