#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include "Expression/Expression.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();
    Expression* expr;

private:
    Ui::Calculator *ui;

private slots:
    void number_pressed();
    void on_decimalButton_released();
};
#endif // CALCULATOR_H
