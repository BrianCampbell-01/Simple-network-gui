#include "network_basic.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    network_basic w;
    w.show();
    return a.exec();
}
