
#include <QApplication>
#include "counter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CounterWin w;
    w.show();
    return a.exec();
}
