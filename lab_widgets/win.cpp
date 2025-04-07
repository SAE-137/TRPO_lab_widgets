#include <QLayout>
#include <QtMath>
#include <QMessageBox>

#include "Win.h"

Win::Win(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Возведение в квадрат");
    frame = new QFrame(this);
    frame->setFrameShadow(QFrame::Raised);
    frame->setFrameShape(QFrame::Panel);
    inputLabel = new QLabel("Введите число:", this);
    inputEdit = new QLineEdit("", this);
    StrValidator* v = new StrValidator(inputEdit);
    inputEdit->setValidator(v);
    outputLabel = new QLabel("Результат:", this);
    outputEdit = new QLineEdit("", this);
    nextButton = new QPushButton("Следующий", this);
    exitButton = new QPushButton("Выход", this);

    QVBoxLayout* vLayout1 = new QVBoxLayout(frame);
    vLayout1->addWidget(inputLabel);
    vLayout1->addWidget(inputEdit);
    vLayout1->addWidget(outputLabel);
    vLayout1->addWidget(outputEdit);
    vLayout1->addStretch();

    QVBoxLayout* vLayout2 = new QVBoxLayout();
    vLayout2->addWidget(nextButton);
    vLayout2->addWidget(exitButton);
    vLayout2->addStretch();

    QHBoxLayout* hLayout = new QHBoxLayout(this);
    hLayout->addWidget(frame);
    hLayout->addLayout(vLayout2);

    begin();

    connect(nextButton, &QPushButton::clicked, this, &Win::begin);
    connect(exitButton, &QPushButton::clicked, this, &QWidget::close);
    connect(inputEdit, &QLineEdit::returnPressed, this, &Win::calc);
}

void Win::begin()
{
    inputEdit->clear();
    nextButton->setEnabled(false);
    nextButton->setDefault(false);
    inputEdit->setEnabled(true);
    outputEdit->setVisible(false);
    outputEdit->setEnabled(false);
    outputLabel->setVisible(false);
    inputEdit->setFocus();
}

void Win::calc()
{
    const QString errorTitle = tr("Ошибка");
    const QString inputErrorMsg = tr("Введено неверное значение.");
    const QString overflowPreventionMsg = tr("Результат слишком велик и может привести к переполнению.");
    const QString overflowMsg = tr("Произошло переполнение при вычислении.");

    bool conversionOk = false;
    const QString inputStr = inputEdit->text().trimmed();

    if (inputStr.isEmpty()) {
        return;
    }

    const double inputValue = inputStr.toDouble(&conversionOk);

    if (!conversionOk) {
        QMessageBox::warning(this, errorTitle, inputErrorMsg);
        return;
    }


    const double maxValueBeforeOverflow = qSqrt(std::numeric_limits<double>::max());
    if (qAbs(inputValue) > maxValueBeforeOverflow) {
        QMessageBox::warning(this, errorTitle, overflowPreventionMsg);
        return;
    }

    const double result = inputValue * inputValue;


    if (qIsInf(result) || qIsNaN(result)) {
        QMessageBox::warning(this, errorTitle, overflowMsg);
        return;
    }


    outputEdit->setText(QString::number(result, 'g', 10));


    inputEdit->setEnabled(false);
    outputLabel->setVisible(true);
    outputEdit->setVisible(true);
    nextButton->setEnabled(true);
    nextButton->setDefault(true);
    nextButton->setFocus();
}
