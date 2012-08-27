
#include "routemeaddress.h"
#include "routemecontroller.h"
#include "routemecoordinate.h"
#include "routememap.h"
#include "routemapobject.h"
#include "routeme.h"
#include "routemeserver.h"
#include "routemeplace.h"
#include "routemepositioninfo.h"
#include "routesearchmanager.h"
#include "routemeroutemanager.h"

#include <QtCore/QUrl>
#include <QtDeclarative/QDeclarativeContext>
#include <QtDeclarative/QDeclarativeEngine>
#include <QtDeclarative/QDeclarativeView>

RouteMe::RouteMe(QWidget *parent)
    : QMainWindow(parent)
    , m_view(new QDeclarativeView(this))
    , m_context(m_view->rootContext())
    , m_controller(new RouteMeController(this))
{
    connect(m_view->engine(), SIGNAL(quit()), SLOT(close()));
    m_context->setContextProperty("controller", m_controller);

    setCentralWidget(m_view);
    m_view->setResizeMode(QDeclarativeView::SizeRootObjectToView);

    qmlRegisterType<RouteMeCoordinate>("com.routeme.types", 1, 0, "RouteCoordinate");
    qmlRegisterType<RouteMePositionInfo>("com.routeme.types", 1, 0, "RoutePositionInfo");
    qmlRegisterType<RouteMapObject>("com.routeme.types", 1, 0, "Route");
    qmlRegisterType<RouteMeRouteManager>("com.routeme.types", 1, 0, "RouteManager");
    qmlRegisterType<RouteMeMap>("com.routeme.types", 1, 0, "RouteMap");
    qmlRegisterType<RouteMeAddress>("com.routeme.types", 1, 0, "RouteAddress");
    qmlRegisterType<RouteMePlace>("com.routeme.types", 1, 0, "RoutePlace");
    qmlRegisterType<RouteSearchManager>("com.routeme.types", 1, 0, "RouteSearchManager");

    m_view->setSource(QUrl("qrc:/qml/main.qml"));

    m_controller->init();
}

RouteMe::~RouteMe()
{
}
