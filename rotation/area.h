#ifndef AREA_H
#define AREA_H

#include "figura.h"
#include <QWidget>



class Area : public QWidget
{
    Q_OBJECT
public:
    explicit Area(QWidget *parent = nullptr);
    ~Area();
    MyLine *myLine = nullptr;
    MyRect *myRect = nullptr;
protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void showEvent(QShowEvent *event);
    void hideEvent(QHideEvent *event);
private:
    int m_myTimer;
    float m_alpha;
};

#endif // AREA_H
