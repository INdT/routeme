#include "serviceprovider.h"

ServiceProvider *ServiceProvider::m_instance = 0;

ServiceProvider *ServiceProvider::instance()
{
    if (!m_instance)
        return new ServiceProvider();

    return m_instance;
}

ServiceProvider::ServiceProvider()
{
    m_serviceProvider = new QGeoServiceProvider("nokia");
}

QGeoMappingManager *ServiceProvider::mappingManager()
{
    if (!m_serviceProvider)
        return 0;

    return m_serviceProvider->mappingManager();
}

QGeoRoutingManager *ServiceProvider::routingManager()
{
    if (!m_serviceProvider)
        return 0;

    return m_serviceProvider->routingManager();
}

QGeoSearchManager *ServiceProvider::searchManager()
{
    if (!m_serviceProvider)
        return 0;

    return m_serviceProvider->searchManager();
}
