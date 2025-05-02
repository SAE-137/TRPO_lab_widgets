
#ifndef FIGURA_H
#define FIGURA_H

#include <QPainter>

class Figura
{
public:
    Figura(int x, int y, int halflen)
        :_x(x), _y(y), _halflen(halflen)
    {}
    virtual ~Figura() = default;
    void move(float alpha, QPainter *painter);
protected:
    int _x, _y, _halflen, _dx, _dy;
    virtual void _draw(QPainter *painter) = 0;
};

class MyLine: public Figura
{
public:
    MyLine(int x, int y, int halflen)
        :Figura(x, y, halflen)
    {}
protected:
    void _draw(QPainter *painter) override;
};

class MyRect: public Figura
{
public:
    MyRect(int x, int y, int halflen)
        :Figura(x, y, halflen)
    {}
protected:
    void _draw(QPainter *painter) override;
};

#endif // FIGURE_H
