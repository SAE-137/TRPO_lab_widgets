#include <QApplication>
#include "win.h"

int main(int argc, char *argv[])
{
   QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QApplication a(argc, argv);
    Win w;
    w.show();
    return a.exec();
}
