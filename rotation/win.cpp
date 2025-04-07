#include <QLayout>

#include "Win.h"

Win::Win()
{
    setWindowTitle("Обработка событий");
    _area = new Area(this);
    _btn = new QPushButton("Завершить", this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(_area);
    layout->addWidget(_btn);
    connect(_btn, &QPushButton::clicked, this, &QWidget::close);
}
