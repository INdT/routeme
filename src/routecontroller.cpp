#include "routecontroller.h"
#include "routemeserver.h"

RouteController::RouteController(QObject *parent)
    : QObject(parent)
    , m_server(new RouteMeServer(this))
{
}

RouteController::~RouteController()
{
}

void RouteController::init()
{
    m_server->listen();
}

