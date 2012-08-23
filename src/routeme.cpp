
#include "routeaddress.h"
#include "routecontroller.h"
#include "routecoordinateitem.h"
#include "routemapitem.h"
#include "routemapobject.h"
#include "routeme.h"
#include "routemeserver.h"
#include "routeplace.h"
#include "routepositioninfo.h"
#include "routesearchmanager.h"
#include "routingmanager.h"

#include <QtCore/QUrl>
#include <QtDeclarative/QDeclarativeContext>
#include <QtDeclarative/QDeclarativeEngine>
#include <QtDeclarative/QDeclarativeView>

RouteMe::RouteMe(QWidget *parent)
    : QMainWindow(parent)
    , m_view(new QDeclarativeView(this))
    , m_context(m_view->rootContext())
    , m_controller(new RouteController(this))
{
    connect(m_view->engine(), SIGNAL(quit()), SLOT(close()));
    m_context->setContextProperty("controller", m_controller);

    setCentralWidget(m_view);
    m_view->setResizeMode(QDeclarativeView::SizeRootObjectToView);

    qmlRegisterType<RouteCoordinateItem>("com.routeme.types", 1, 0, "RouteCoordinate");
    qmlRegisterType<RoutePositionInfo>("com.routeme.types", 1, 0, "RoutePositionInfo");
    qmlRegisterType<RouteMapObject>("com.routeme.types", 1, 0, "Route");
    qmlRegisterType<RoutingManager>("com.routeme.types", 1, 0, "RouteManager");
    qmlRegisterType<RouteMapItem>("com.routeme.types", 1, 0, "RouteMeMap");
    qmlRegisterType<RouteAddress>("com.routeme.types", 1, 0, "RouteAddress");
    qmlRegisterType<RoutePlace>("com.routeme.types", 1, 0, "RoutePlace");
    qmlRegisterType<RouteSearchManager>("com.routeme.types", 1, 0, "RouteSearchManager");

    m_view->setSource(QUrl("qrc:/qml/main.qml"));

    m_controller->init();
}

RouteMe::~RouteMe()
{
}
