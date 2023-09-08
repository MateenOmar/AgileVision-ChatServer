#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>

namespace AgileVision{
class Socket;

class Server : public QTcpServer
{
public:
    Server(QObject *parent = nullptr);
    bool startServer(quint16 port);

protected:
    void incomingConnection(qintptr handle);

private:
    QList<Socket *> sockets;
};
}//END namespace

#endif // SERVER_H
