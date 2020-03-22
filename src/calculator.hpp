#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

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
    void setExpr(QString);
    void exprCheck();
    void clearExpr();
    void clearErr();
    void clearDisplayedAns();
    void calculate();
    void errorHandler(BaseException*);

private:
    Ui::Calculator *ui;
    Expression<QString>* expr;
    Memory<double> mem;

private slots:
    void number_pressed();
    void operation_pressed();
//    void memoryOperation_pressed();
    void update_display();
    void on_btnDecimal_released();
    void on_btnClear_released();
    void on_btnClearExpr_released();
    void on_btnSum_released();
    void on_btnAns_pressed();
    void on_btnMC_released();
    void on_btnMR_released();
};
#endif // CALCULATOR_HPP
