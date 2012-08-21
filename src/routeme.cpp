
#include "routeme.h"
#include "routemeserver.h"
#include "routemapitem.h"
#include "routecoordinateitem.h"
#include "routepositioninfo.h"

#include <QDeclarativeView>
#include <QDeclarativeContext>
#include <QDeclarativeEngine>
#include <QUrl>

RouteMe::RouteMe(QWidget *parent)
    : QMainWindow(parent)
    , m_view(new QDeclarativeView(this))
    , m_context(m_view->rootContext())
{
    connect(m_view->engine(), SIGNAL(quit()), SLOT(close()));

    setCentralWidget(m_view);
    m_view->setResizeMode(QDeclarativeView::SizeRootObjectToView);

    qmlRegisterType<RouteCoordinateItem>("com.routeme.types", 1, 0, "RouteCoordinate");
    qmlRegisterType<RoutePositionInfo>("com.routeme.types", 1, 0, "RoutePositionInfo");
    qmlRegisterType<RouteMapItem>("com.routeme.types", 1, 0, "RouteMeMap");

    m_view->setSource(QUrl("qrc:/qml/main.qml"));

    m_server = new RouteMeServer(this);
    m_server->listen();
}

RouteMe::~RouteMe()
{
}
