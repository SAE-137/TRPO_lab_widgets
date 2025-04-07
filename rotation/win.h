#ifndef WIN_H
#define WIN_H

#include <QWidget>
#include <QPushButton>

#include "Area.h"

class Win : public QWidget
{
    Q_OBJECT
public:
    Win();
protected:
    Area *_area = nullptr;
    QPushButton *_btn = nullptr;
};
#endif // WIN_H
