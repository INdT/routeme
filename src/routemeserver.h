#ifndef _ROUTEMESERVER_H_
#define _ROUTEMESERVER_H_

#include <QtCore/QObject>
#include <QtCore/QVariantMap>

class QTcpServer;
class QTcpSocket;

class RouteMeServer : public QObject
{
    Q_OBJECT

public:
    RouteMeServer(QObject *parent);

    quint16 port() const { return m_port; }
    void setPort(quint16 port);

    void listen();

protected:
    QVariantMap parseData(const QByteArray &data, bool &ok);

protected slots:
    void onNewConnection();
    void onReadyRead();

signals:
    void portChanged(quint16 port);
    void dataReceived(QVariantMap data);

private:
    void init();

private:
    QTcpServer *m_server;
    QTcpSocket *m_client;
    quint16 m_port;
};


#endif /* _ROUTEMESERVER_H_ */
