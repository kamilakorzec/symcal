#include "symcal.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SymCal w;
    w.show();

    return a.exec();
}
