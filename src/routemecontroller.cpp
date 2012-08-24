#include "routemecontroller.h"
#include "routemeserver.h"

RouteMeController::RouteMeController(QObject *parent)
    : QObject(parent)
    , m_server(new RouteMeServer(this))
{
}

RouteMeController::~RouteMeController()
{
}

void RouteMeController::init()
{
    m_server->listen();
}

