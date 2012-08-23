#ifndef ROUTESEARCHMANAGER_H
#define ROUTESEARCHMANAGER_H

#include <QtCore/QObject>
#include <qgeosearchreply.h>
#include <qgeosearchmanager.h>

class RouteCoordinateItem;
class RoutePlace;

using namespace QtMobility;

class RouteSearchManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(RouteCoordinateItem* coordinate READ coordinate WRITE setCoordinate NOTIFY coordinateChanged)
    Q_PROPERTY(RoutePlace* place READ place NOTIFY placeAvailable)

public:
    RouteSearchManager(QObject *parent = 0);
    ~RouteSearchManager();

    RouteCoordinateItem* coordinate();
    void setCoordinate(RouteCoordinateItem* coordinate);

    RoutePlace* place();

    Q_INVOKABLE void searchPlace();

signals:
    void coordinateChanged();
    void placeAvailable();

private slots:
    void onReverseGeocodeFinished();

private:
    void init();

    QGeoSearchManager *m_searchManager;
    RouteCoordinateItem *m_coordinate;
    RoutePlace *m_place;
};

#endif
