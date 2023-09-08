#include <QCoreApplication>
#include "server.h"

using namespace AgileVision;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Server server;
    if (!server.startServer(3333)){
        qDebug() << "Error:" << server.errorString();
        return 1;
    }
    qDebug() << "Server Started";
    return a.exec();
}
