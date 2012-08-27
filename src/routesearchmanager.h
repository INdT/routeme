#ifndef ROUTESEARCHMANAGER_H
#define ROUTESEARCHMANAGER_H

#include <QtCore/QObject>
#include <qgeosearchreply.h>
#include <qgeosearchmanager.h>

class RouteMeCoordinate;
class RouteMePlace;

using namespace QtMobility;

class RouteSearchManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(RouteMeCoordinate* coordinate READ coordinate WRITE setCoordinate NOTIFY coordinateChanged)
    Q_PROPERTY(RouteMePlace* place READ place NOTIFY placeAvailable)

public:
    RouteSearchManager(QObject *parent = 0);
    ~RouteSearchManager();

    RouteMeCoordinate* coordinate();
    void setCoordinate(RouteMeCoordinate* coordinate);

    RouteMePlace* place();

    Q_INVOKABLE void searchPlace();

signals:
    void coordinateChanged();
    void placeAvailable();

private slots:
    void onReverseGeocodeFinished();

private:
    void init();

    QGeoSearchManager *m_searchManager;
    RouteMeCoordinate *m_coordinate;
    RouteMePlace *m_place;
};

#endif