#include "routemeaddress.h"

RouteMeAddress::RouteMeAddress(QObject *parent)
    : QObject(parent)
{
}

RouteMeAddress::~RouteMeAddress()
{
}

void RouteMeAddress::setCity(const QString &city)
{
    m_city = city;
    emit cityChanged();
}

void RouteMeAddress::setCountry(const QString &country)
{
    m_country = country;
    emit countryChanged();
}

void RouteMeAddress::setDistrict(const QString &district)
{
    m_district = district;
    emit districtChanged();
}

void RouteMeAddress::setPostcode(const QString &postcode)
{
    m_postcode = postcode;
    emit postcodeChanged();
}

void RouteMeAddress::setState(const QString &state)
{
    m_state = state;
    emit stateChanged();
}

void RouteMeAddress::setStreet(const QString &street)
{
    m_street = street;
    emit streetChanged();
}

void RouteMeAddress::setGeoAddress(const QGeoAddress &address)
{
    m_address = address;
    fillAddress();
}

void RouteMeAddress::fillAddress()
{
    setCity(m_address.city());
    setCountry(m_address.country());
    setDistrict(m_address.district());
    setPostcode(m_address.postcode());
    setState(m_address.state());
    setStreet(m_address.street());
}
