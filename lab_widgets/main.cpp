#include <QApplication>

#include "win.h"




int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Win w;
    w.show();
    return a.exec();
}
