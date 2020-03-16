#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include "Expression/Expression.hpp"
#include "Expression/Memory.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();
    double getAns();

private:
    Ui::Calculator *ui;
    Expression<string>* expr;
    Memory<string> mem;
    double ans;

private slots:
    void number_pressed();
    void unaryOperation_pressed();
    void binaryOperation_pressed();
    void memoryOperation_pressed();
    void update_display();
    void on_btnDecimal_released();
    void on_btnClear_released();
    void on_btnClearExpr_released();
};
#endif // CALCULATOR_H
