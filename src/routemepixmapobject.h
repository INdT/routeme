#ifndef ROUTEMEPIXMAPOBJECT_H
#define ROUTEMEPIXMAPOBJECT_H

#include <QtCore/QObject>

#include "routemecoordinate.h"

#include <qgeomappixmapobject.h>

using namespace QtMobility;

class RouteMePixmapObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(RouteMeCoordinate* coordinate READ coordinate WRITE setCoordinate NOTIFY coordinateChanged)
    Q_PROPERTY(QString source READ source WRITE setSource NOTIFY sourceChanged)

public:
    RouteMePixmapObject(QObject *parent = 0);
    ~RouteMePixmapObject();

    RouteMeCoordinate* coordinate();
    void setCoordinate(RouteMeCoordinate* coordinate);

    QString source() const;
    void setSource(const QString &source);

    QGeoMapPixmapObject* pixmapObject() { return m_pixmapObject; }

signals:
    void coordinateChanged();
    void sourceChanged();

private:
    QGeoMapPixmapObject *m_pixmapObject;
    QString m_source;
};

#endif
