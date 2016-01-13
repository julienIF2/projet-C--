#include "qihm.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QIHM w;
    w.show();

    return a.exec();
}
