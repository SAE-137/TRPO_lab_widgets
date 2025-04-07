#include <QSize>
#include <QTimerEvent>

#include "area.h"

Area::Area(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(QSize (300, 200));
    myLine = new MyLine(80, 100, 50);
    myRect = new MyRect(220, 100, 50);
    m_alpha = 0;
}

void Area::showEvent(QShowEvent *)
{
    m_myTimer = startTimer(50);
}

void Area::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(Qt::red);
    myLine->move(m_alpha, &painter);
    myRect->move(m_alpha * (-0.5), &painter);
}

void Area::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == m_myTimer) {
        m_alpha = m_alpha + 0.2;
        update();
    }
    else {
        QWidget::timerEvent(event);
    }
}

void Area::hideEvent(QHideEvent *)
{
    killTimer(m_myTimer);
}

Area::~Area()
{
    delete myLine;
    delete myRect;
}
