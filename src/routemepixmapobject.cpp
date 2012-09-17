#include "routemepixmapobject.h"

#include <QtGui/QPixmap>

RouteMePixmapObject::RouteMePixmapObject(QObject *parent)
    : QObject(parent)
    , m_pixmapObject(new QGeoMapPixmapObject)
{
}

RouteMePixmapObject::~RouteMePixmapObject()
{
}

RouteMeCoordinate* RouteMePixmapObject::coordinate()
{
    RouteMeCoordinate *coord = new RouteMeCoordinate(this);
    coord->setLatitude(m_pixmapObject->coordinate().latitude());
    coord->setLongitude(m_pixmapObject->coordinate().longitude());

    return coord;
}

void RouteMePixmapObject::setCoordinate(RouteMeCoordinate* coordinate)
{
    QGeoCoordinate coord;
    coord.setLatitude(coordinate->latitude());
    coord.setLongitude(coordinate->longitude());

    m_pixmapObject->setCoordinate(coord);

    emit coordinateChanged();
}

QString RouteMePixmapObject::source() const
{
    return m_source;
}

void RouteMePixmapObject::setSource(const QString &source)
{
    m_source = source;
    QPixmap pixmap(m_source, "PNG");
    m_pixmapObject->setPixmap(pixmap);
    emit sourceChanged();
}
