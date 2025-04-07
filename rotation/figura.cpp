
#include <math.h>
#include "figura.h"

void Figura::move(float alpha, QPainter *painter)
{
    _dx = _halflen * cos(alpha);
    _dy = _halflen * sin(alpha);
    _draw(painter);
}

void MyLine::_draw(QPainter *painter)
{
    painter->drawLine(_x + _dx, _y + _dy, _x - _dx, _y - _dy);
}

void MyRect::_draw(QPainter *painter)
{
    painter->drawLine(_x + _dx, _y + _dy, _x + _dy, _y - _dx);
    painter->drawLine(_x + _dy, _y - _dx, _x - _dx, _y - _dy);
    painter->drawLine(_x - _dx, _y - _dy, _x - _dy, _y + _dx);
    painter->drawLine(_x - _dy, _y + _dx, _x + _dx, _y + _dy);
}
