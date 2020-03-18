#include "calculator.hpp"
#include "ui_calculator.h"
//#include "Expression/Expression.hpp"
#include "Expression/TerminalExpression.hpp"
#include "Expression/Unary/UnaryExpression.hpp"
#include "Expression/Binary/BinaryExpression.hpp"
#include "Expression/Unary/NegativeExpression.hpp"
#include "Expression/Unary/PercentExpression.hpp"
#include "Expression/Unary/SquareExpression.hpp"
#include "Expression/Unary/SqrtExpression.hpp"
#include "Expression/Unary/Trigonometry/SinExpression.hpp"
#include "Expression/Unary/Trigonometry/CosExpression.hpp"
#include "Expression/Unary/Trigonometry/TanExpression.hpp"
#include "Exception/OperationFailedException.hpp"
#include "Exception/DigitLimitException.hpp"

#include <string>
#include <QtDebug>

Calculator::Calculator(QWidget *parent) : QMainWindow(parent), ui(new Ui::Calculator)
{
    ui->setupUi(this);
    this->setFixedSize(428, 500);
    expr = new TerminalExpression<QString>("");
    isErr = false;
    // Number
    connect(ui->btnNum00, SIGNAL(released()), this, SLOT(number_pressed()));
    connect(ui->btnNum0, SIGNAL(released()), this, SLOT(number_pressed()));
    connect(ui->btnNum1, SIGNAL(released()), this, SLOT(number_pressed()));
    connect(ui->btnNum2, SIGNAL(released()), this, SLOT(number_pressed()));
    connect(ui->btnNum3, SIGNAL(released()), this, SLOT(number_pressed()));
    connect(ui->btnNum4, SIGNAL(released()), this, SLOT(number_pressed()));
    connect(ui->btnNum5, SIGNAL(released()), this, SLOT(number_pressed()));
    connect(ui->btnNum6, SIGNAL(released()), this, SLOT(number_pressed()));
    connect(ui->btnNum7, SIGNAL(released()), this, SLOT(number_pressed()));
    connect(ui->btnNum8, SIGNAL(released()), this, SLOT(number_pressed()));
    connect(ui->btnNum9, SIGNAL(released()), this, SLOT(number_pressed()));
    // Unary Operation
    connect(ui->btnPercent, SIGNAL(released()), this, SLOT(operation_pressed()));
    connect(ui->btnSquare, SIGNAL(released()), this, SLOT(operation_pressed()));
    connect(ui->btnSqrt, SIGNAL(released()), this, SLOT(operation_pressed()));
    connect(ui->btnSin, SIGNAL(released()), this, SLOT(operation_pressed()));
    connect(ui->btnCos, SIGNAL(released()), this, SLOT(operation_pressed()));
    connect(ui->btnTan, SIGNAL(released()), this, SLOT(operation_pressed()));
    // Binary Operation
    connect(ui->btnAdd, SIGNAL(released()), this, SLOT(operation_pressed()));
    connect(ui->btnSub, SIGNAL(released()), this, SLOT(operation_pressed()));
    connect(ui->btnMultiply, SIGNAL(released()), this, SLOT(operation_pressed()));
    connect(ui->btnDiv, SIGNAL(released()), this, SLOT(operation_pressed()));
    // Other Operation
    connect(ui->btnOpen, SIGNAL(released()), this, SLOT(operation_pressed()));
    connect(ui->btnClose, SIGNAL(released()), this, SLOT(operation_pressed()));
    // Memory Operation
    connect(ui->btnMC, SIGNAL(released()), this, SLOT(memoryOperation_pressed()));
    connect(ui->btnMR, SIGNAL(released()), this, SLOT(memoryOperation_pressed()));
}

Calculator::~Calculator()
{
    delete ui;
    delete expr;
}

void Calculator::setExpr(QString qStr)
{
    if (qStr.length() > 14) {
        throw new DigitLimitException();
    } else {
        delete expr;
        expr = new TerminalExpression<QString>(qStr);
    }

}

void Calculator::setAns(double exprValue)
{
    ans = exprValue;
}

void Calculator::clearExpr()
{
    delete expr;
    expr = new TerminalExpression<QString>("");
}

void Calculator::clearErr()
{
    if (isErr) {
        clearExpr();
        isErr = false;
    }
}

void Calculator::number_pressed()
{
    clearErr();
    QPushButton* button = (QPushButton*) sender();
    try {
        setExpr((expr->solve() + button->text()));
        update_display();
    } catch (BaseException * exc) {
        OperationFailedException* err = new OperationFailedException(exc);
        setExpr(QString::fromStdString(err->getMessage()));
        update_display();
        isErr = true;
    }
}

void Calculator::operation_pressed()
{
    clearErr();
    QPushButton* button = (QPushButton*) sender();
    try {
        if (button->text() == "x²") {
            setExpr((expr->solve() + "²"));
        } else {
            setExpr((expr->solve() + button->text()));
            if (button->text() == "SIN" || button->text() == "COS" || button->text() == "TAN") {
                setExpr(expr->solve() + "(");
            }
        }
        update_display();
    } catch (BaseException * exc) {
        OperationFailedException* err = new OperationFailedException(exc);
        setExpr(QString::fromStdString(err->getMessage()));
        update_display();
        isErr = true;
    }
}

void Calculator::memoryOperation_pressed()
{
    QPushButton* button = (QPushButton*) sender();
    if (button->text() == "MC") {
        // CEK VALID GA EXPRESI NYA
        mem.MC(new TerminalExpression<double>(expr->solve().toDouble()));
    } else if (button->text() == "MR") {
        QString labelValue;
        try {
            labelValue = QString::number(mem.MR()->solve(), 'g', 15);
            setExpr(labelValue);
            update_display();
        } catch (BaseException* exc) {
            OperationFailedException* err = new OperationFailedException(exc);
            setExpr(QString::fromStdString(err->getMessage()));
            update_display();
            isErr = true;
        }
    }
}

void Calculator::on_btnDecimal_released()
{
    try {
        setExpr(expr->solve() + ".");
        update_display();
    } catch (BaseException * exc) {
        OperationFailedException* err = new OperationFailedException(exc);
        setExpr(QString::fromStdString(err->getMessage()));
        update_display();
        isErr = true;
    }
}

void Calculator::update_display()
{
    qDebug() << expr->solve();
    ui->display->setText(expr->solve());
}

void Calculator::on_btnClearExpr_released()
{
    clearExpr();
    update_display();
}

void Calculator::on_btnClear_released()
{
    clearExpr();
    mem.clear();
    update_display();
}
