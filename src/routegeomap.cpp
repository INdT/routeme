#include "routegeomap.h"

#include <QtCore/QParallelAnimationGroup>
#include <QtCore/QPropertyAnimation>
#include <QtGui/QGraphicsSceneMouseEvent>
#include <QtGui/QGraphicsSceneWheelEvent>

#include "qgeocoordinate.h"

RouteGeoMap::RouteGeoMap(QGeoMappingManager *manager,  QGraphicsItem *parent)
    : QGraphicsGeoMap(manager, parent)
    , panActive(false)
    , markerPressed(false)
    , objectPressed(0)
{
    setFocus();
}

RouteGeoMap::~RouteGeoMap()
{
}

double RouteGeoMap::centerLatitude() const
{
    return center().latitude();
}

double RouteGeoMap::centerLongitude() const
{
    return center().longitude();
}

void RouteGeoMap::setCenterLatitude(qreal lat)
{
    QGeoCoordinate c = center();
    c.setLatitude(lat);
    setCenter(c);
}

void RouteGeoMap::setCenterLongitude(qreal lon)
{
    QGeoCoordinate c = center();
    c.setLongitude(lon);
    setCenter(c);
}

void RouteGeoMap::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    panActive = true;
    markerPressed = false;
    QList<QGeoMapObject*> objects = mapObjectsAtScreenPosition(event->pos());
    if (objects.size() > 0) {
        objectPressed = objects.first();
        markerPressed = true;
    }

    setFocus();
    event->accept();
}

void RouteGeoMap::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    panActive = false;

    if (markerPressed) {
        // check if we're still over the object
        QList<QGeoMapObject*> objects = mapObjectsAtScreenPosition(event->pos());
        if (objects.contains(objectPressed)) {
            emit clicked(objectPressed);
        }

        markerPressed = false;
    }

    setFocus();
    event->accept();
}

void RouteGeoMap::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (panActive) {
        QPointF delta = event->lastPos() - event->pos();
        pan(delta.x(), delta.y());
        emit panned();
    }
    setFocus();
    event->accept();
}

void RouteGeoMap::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    // pan our current point to the centre, zoom, then pan back

    qreal panx = event->pos().x() - size().width() / 2.0;
    qreal pany = event->pos().y() - size().height() / 2.0;
    pan(panx, pany);
    if (event->delta() > 0) {   // zoom in
        if (zoomLevel() < maximumZoomLevel()) {
            setZoomLevel(zoomLevel() + 1);
        }
    } else {                    // zoom out
        if (zoomLevel() > minimumZoomLevel()) {
            setZoomLevel(zoomLevel() - 1);
        }
    }
    pan(-panx, -pany);
    this->setFocus();
    event->accept();
}

void RouteGeoMap::keyPressEvent(QKeyEvent *event)
{
    QGeoCoordinate center;
    QPropertyAnimation *anim;
    const qreal width = size().width();
    const qreal height = size().height();

    switch (event->key()) {
    case Qt::Key_4:
    case Qt::Key_Left:
        center = screenPositionToCoordinate(
                    QPointF(width/2 - width/5, height/2));
        anim = new QPropertyAnimation(this, "centerLongitude");
        anim->setEndValue(center.longitude());
        anim->setDuration(200);
        anim->start(QAbstractAnimation::DeleteWhenStopped);
        break;
    case Qt::Key_6:
    case Qt::Key_Right:
        center = screenPositionToCoordinate(
                    QPointF(width/2 + width/5, height/2));
        anim = new QPropertyAnimation(this, "centerLongitude");
        anim->setEndValue(center.longitude());
        anim->setDuration(200);
        anim->start(QAbstractAnimation::DeleteWhenStopped);
        break;
    case Qt::Key_2:
    case Qt::Key_Up:
        center = screenPositionToCoordinate(
                    QPointF(width/2, height/2 - height/5));
        anim = new QPropertyAnimation(this, "centerLatitude");
        anim->setEndValue(center.latitude());
        anim->setDuration(200);
        anim->start(QAbstractAnimation::DeleteWhenStopped);
        break;
    case Qt::Key_8:
    case Qt::Key_Down:
        center = screenPositionToCoordinate(
                    QPointF(width/2, height/2 + height/5));
        anim = new QPropertyAnimation(this, "centerLatitude");
        anim->setEndValue(center.latitude());
        anim->setDuration(200);
        anim->start(QAbstractAnimation::DeleteWhenStopped);
        break;
    case Qt::Key_1:
        if (zoomLevel() > minimumZoomLevel()) {
            setZoomLevel(zoomLevel() - 1);
        }
        break;
    case Qt::Key_3:
        if (zoomLevel() < maximumZoomLevel()) {
            setZoomLevel(zoomLevel() + 1);
        }
        break;
    }
    setFocus();
    event->accept();
}
