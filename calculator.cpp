#include "calculator.hpp"
#include "ui_calculator.h"
#include "Data.hpp"
#include "Expression/TerminalExpression.hpp"
#include "Exception/OperationFailedException.hpp"
#include "Exception/InvalidExpressionException.hpp"
#include "Exception/DivideByZeroException.hpp"

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
    delete expr;
    expr = new TerminalExpression<QString>(qStr);
}

void Calculator::setAns(double exprValue)
{
    ans = exprValue;
}

void Calculator::exprCheck()
{
    QString str = expr->solve();
    if (str.length() == 0) throw new InvalidExpressionException("EMPTY");
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == "-" && (str[i+1] == "-" || i+1 == str.length())) {
            throw new InvalidExpressionException("DOUBLE NEG");
        }
        if (str[i] == "÷" && (str[i+1] == "0" || i+1 == str.length())) {
            throw new DivideByZeroException();
        }
        if (str[i] == ".") {
            bool foundDecimal = true;
//            qDebug() << i;
            for (int j = i+1; j < str.length() && foundDecimal; j++) {
                if (foundDecimal && (str[j] == "+" || str[j] == "-" || str[j] == "x" || str[j] == "÷" || str[j] == "√")) {
                    foundDecimal = false;
                }
                if (foundDecimal && (str[j] == "." || str[j] == "S" || str[j] == "C" || str[j] == "T" || str[j] == "%" || str[j] == "²")) {
//                    qDebug() << str[j];
                    throw new InvalidExpressionException("DECIMAL");
                    break;
                }
            }
        }
    }
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
    setExpr((expr->solve() + button->text()));
    update_display();
}

void Calculator::operation_pressed()
{
    clearErr();
    QPushButton* button = (QPushButton*) sender();
    if (button->text() == "x²") {
        setExpr((expr->solve() + "²"));
    } else {
        setExpr((expr->solve() + button->text()));
        if (button->text() == "SIN" || button->text() == "COS" || button->text() == "TAN") {
            setExpr(expr->solve() + "(");
        }
    }
    update_display();
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
    setExpr(expr->solve() + ".");
    update_display();
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

void Calculator::on_btnSum_released()
{
    try {
        exprCheck();
    } catch (BaseException* exc) {
        OperationFailedException* err = new OperationFailedException(exc);
        setExpr(QString::fromStdString(err->getMessage()));
        update_display();
        isErr = true;
    }

    QString val = expr->solve();
    val.replace("√", "~");
    val.replace("²", "^");
    qDebug() << val;
    Data x(val.toStdString());
    qDebug() << x.solve();

}

