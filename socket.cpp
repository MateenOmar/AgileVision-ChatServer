#include "socket.h"

namespace AgileVision{
Socket::Socket(qintptr handle, QObject *parent) : QTcpSocket(parent)
{
    setSocketDescriptor(handle);

    connect(this, &Socket::readyRead, [&](){
        emit ReadyRead(this);
    });

    connect(this, &Socket::stateChanged, [&] (int S){
        emit StateChanged(this, S);
    });
}
}//END namespace
