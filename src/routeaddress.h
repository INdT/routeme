#ifndef ROUTEADDRESS_H
#define ROUTEADDRESS_H

#include <QtCore/QObject>
#include <qgeoaddress.h>

using namespace QtMobility;

class RouteAddress : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString city READ city WRITE setCity NOTIFY cityChanged)
    Q_PROPERTY(QString country READ country WRITE setCountry NOTIFY countryChanged)
    Q_PROPERTY(QString district READ district WRITE setDistrict NOTIFY districtChanged)
    Q_PROPERTY(QString postcode READ postcode WRITE setPostcode NOTIFY postcodeChanged)
    Q_PROPERTY(QString state READ state WRITE setState NOTIFY stateChanged)
    Q_PROPERTY(QString street READ street WRITE setStreet NOTIFY streetChanged)

public:
    RouteAddress(QObject *parent = 0);
    ~RouteAddress();

    QString city() const { return m_city; }
    void setCity(const QString &city);

    QString country() const { return m_country; }
    void setCountry(const QString &country);

    QString district() const { return m_district; }
    void setDistrict(const QString &district);

    QString postcode() const { return m_postcode; }
    void setPostcode(const QString &postcode);

    QString state() const { return m_state; }
    void setState(const QString &state);

    QString street() const { return m_street; }
    void setStreet(const QString &street);

    void setGeoAddress(const QGeoAddress &address);

signals:
    void cityChanged();
    void countryChanged();
    void districtChanged();
    void postcodeChanged();
    void stateChanged();
    void streetChanged();

private:
    void fillAddress();

    QString m_city;
    QString m_country;
    QString m_district;
    QString m_postcode;
    QString m_state;
    QString m_street;

    QGeoAddress m_address;
};

#endif
