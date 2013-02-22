#include "routemeserver.h"

#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QtCore/QDataStream>

RouteMeServer::RouteMeServer(QObject *parent)
    : QObject(parent)
    , m_server(0)
    , m_client(0)
    , m_port(8082)
{
    init();
}

void RouteMeServer::init()
{
    m_server = new QTcpServer(this);

    connect(m_server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}

void RouteMeServer::setPort(quint16 port)
{
    if (m_port == port)
        return;

    m_port = port;

    emit portChanged(m_port);
}

void RouteMeServer::listen()
{
    if (!m_server)
        return;

    if (!m_server->listen(QHostAddress::Any, m_port))
        qCritical("Unable to listen: %s", m_server->errorString().toUtf8().constData());
}

void RouteMeServer::onNewConnection()
{
    QTcpSocket *clientSocket = m_server->nextPendingConnection();

    if (!clientSocket)
        return;

    if (m_client)
        m_client->disconnect();

    m_client = clientSocket;

    connect(m_client, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
}

void RouteMeServer::onReadyRead() {
    QByteArray data = m_client->readAll();

    bool ok = false;

    QVariantMap parsedMap = parseData(data, ok);
    if (!ok)
        return;

    emit dataReceived(parsedMap);
}

QVariantMap RouteMeServer::parseData(const QByteArray &data, bool &ok)
{
    // TODO: parse JSON data from daemon
    Q_UNUSED(data);
    Q_UNUSED(ok);

    return QVariantMap();
}
