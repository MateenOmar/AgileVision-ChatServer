#include "server.h"
#include "socket.h"

#include <QDebug>
#include <QTextStream>

namespace AgileVision{
Server::Server(QObject *parent) : QTcpServer(parent)
{
}

bool Server::startServer(quint16 port){
    return listen(QHostAddress::Any, port);
}

void Server::incomingConnection(qintptr handle){
    qDebug() << "Server: Client connected with handle " << handle;
    auto socket = new Socket(handle, this);
    sockets << socket;

    for(auto i : sockets){
        QTextStream T(i);
        T << "Server: Someone has Joined the Chat";
        i->flush();
    }

    connect(socket, &Socket::ReadyRead, [&](Socket *S) {
        qDebug() << "message sent from " << handle;
        QTextStream T(S);
        auto text = T.readAll();

        for(auto i : sockets){
            QTextStream K(i);
            K << text;
            i->flush();
        }
    });
    
    connect(socket, &Socket::StateChanged, [&](Socket *S, int ST){
        qDebug() << "State Changed with handle"  << S->socketDescriptor();
        if(ST == QTcpSocket::UnconnectedState){
            qDebug() << "Unconnected State with handle" << S->socketDescriptor();
            sockets.removeOne(S);
            for(auto i : sockets){
                QTextStream K(i);
                K << "Server: Someone has Disconnected";
                i->flush();
            }
        }
    });
}
}//END namespace
