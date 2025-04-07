#ifndef WIN_H
#define WIN_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

class Counter : public QLineEdit
{
    Q_OBJECT
public:
    Counter(const QString &contents, QWidget *parent = nullptr);
signals:
    void tick_signal();
public slots:
    void add_one()
    {
        QString str = text();
        int r = str.toInt();
        if ((r != 0) && ((r+1) % 5 == 0))
            emit tick_signal();
        r++;
        str.setNum(r);
        setText(str);
    }
};

class CounterWin : public QWidget
{
    Q_OBJECT
protected:
    QLabel *label1 = nullptr, *label2 = nullptr;
    Counter *edit1 = nullptr, *edit2 = nullptr;
    QPushButton *calcButton = nullptr;
    QPushButton *exitButton = nullptr;
public:
    CounterWin(QWidget *parent = nullptr);
};

#endif
