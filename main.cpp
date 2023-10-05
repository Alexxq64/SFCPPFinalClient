#include "mainwindow.h"
#include "client.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    if (!createClientSocket())
        return -1;

    registerClient();
    getPresentClientsList();
    SetConsoleOutputCP(CP_UTF8);

    std::thread receiveThread(receiveMessages);
    std::thread consoleThread(console);

    receiveThread.join();
    consoleThread.join();

    WSACleanup();

    return a.exec();
}
