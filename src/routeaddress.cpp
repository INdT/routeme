#include "routeaddress.h"

RouteAddress::RouteAddress(QObject *parent)
    : QObject(parent)
{
}

RouteAddress::~RouteAddress()
{
}

void RouteAddress::setCity(const QString &city)
{
    m_city = city;
    emit cityChanged();
}

void RouteAddress::setCountry(const QString &country)
{
    m_country = country;
    emit countryChanged();
}

void RouteAddress::setDistrict(const QString &district)
{
    m_district = district;
    emit districtChanged();
}

void RouteAddress::setPostcode(const QString &postcode)
{
    m_postcode = postcode;
    emit postcodeChanged();
}

void RouteAddress::setState(const QString &state)
{
    m_state = state;
    emit stateChanged();
}

void RouteAddress::setStreet(const QString &street)
{
    m_street = street;
    emit streetChanged();
}

void RouteAddress::setGeoAddress(const QGeoAddress &address)
{
    m_address = address;
    fillAddress();
}

void RouteAddress::fillAddress()
{
    setCity(m_address.city());
    setCountry(m_address.country());
    setDistrict(m_address.district());
    setPostcode(m_address.postcode());
    setState(m_address.state());
    setStreet(m_address.street());
}
