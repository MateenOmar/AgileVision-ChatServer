#ifndef SOCKET_H
#define SOCKET_H

#include <QTcpSocket>

namespace AgileVision{
class Socket : public QTcpSocket
{
    Q_OBJECT
public:
    Socket(qintptr handle, QObject *Parent = nullptr);

signals:
    void ReadyRead(Socket *);
    void StateChanged(Socket *, int);
};
}//END namespace

#endif // SOCKET_H
