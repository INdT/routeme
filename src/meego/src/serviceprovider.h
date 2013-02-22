#ifndef SERVICEPROVIDER_H
#define SERVICEPROVIDER_H

#include <qgeoserviceprovider.h>
#include <qgeomappingmanager.h>
#include <qgeosearchmanager.h>

using namespace QtMobility;

class ServiceProvider
{

public:
    static ServiceProvider *instance();

    QGeoMappingManager *mappingManager();
    QGeoRoutingManager *routingManager();
    QGeoSearchManager *searchManager();

private:
    ServiceProvider();
    ~ServiceProvider();

    static ServiceProvider *m_instance;

    QGeoServiceProvider *m_serviceProvider;
};

#endif
