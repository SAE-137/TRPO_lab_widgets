#ifndef WIN_H
#define WIN_H

#include<QWidget>
#include <QtGui>
#include<QFrame>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>

class Win : public QWidget
{

    Q_OBJECT
protected:
    QTextCodec* codec;
    QFrame* frame;
    QLabel* inputLabel;
    QLineEdit *inputEdit;
    QLabel *outputLabel;
    QLineEdit *outputEdit;
    QPushButton *nextButton;
    QPushButton *exitButton;

public:
    Win(QWidget* parent = nullptr);

public slots:
    void begin();
    void calc();

};

#endif // WIN_H
