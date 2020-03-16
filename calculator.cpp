#include "calculator.h"
#include "ui_calculator.h"
//#include "Expression/Expression.hpp"
#include "Expression/TerminalExpression.hpp"
#include "Expression/UnaryExpression.hpp"
#include "Expression/BinaryExpression.hpp"
#include "Expression/NegativeExpression.hpp"
#include "Expression/PercentExpression.hpp"
#include "Expression/SquareExpression.hpp"
#include "Expression/SqrtExpression.hpp"
#include "Expression/SinExpression.hpp"
#include "Expression/CosExpression.hpp"
#include "Expression/TanExpression.hpp"

#include <string>
#include <QtDebug>

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
    this->setFixedSize(428, 500);
    expr = new TerminalExpression<double>(0);
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
    connect(ui->btnPercent, SIGNAL(released()), this, SLOT(unaryOperation_pressed()));
    connect(ui->btnSquare, SIGNAL(released()), this, SLOT(unaryOperation_pressed()));
    connect(ui->btnSqrt, SIGNAL(released()), this, SLOT(unaryOperation_pressed()));
    connect(ui->btnSin, SIGNAL(released()), this, SLOT(unaryOperation_pressed()));
    connect(ui->btnCos, SIGNAL(released()), this, SLOT(unaryOperation_pressed()));
    connect(ui->btnTan, SIGNAL(released()), this, SLOT(unaryOperation_pressed()));
    // Binary Operation
    connect(ui->btnAdd, SIGNAL(released()), this, SLOT(binaryOperation_pressed()));

    // Memory Operation
    connect(ui->btnMC, SIGNAL(released()), this, SLOT(memoryOperation_pressed()));
    connect(ui->btnMR, SIGNAL(released()), this, SLOT(memoryOperation_pressed()));
}

Calculator::~Calculator()
{
    delete ui;
}

double Calculator::getAns() {
    return ans;
}

void Calculator::number_pressed()
{
    delete expr;
    QPushButton* button = (QPushButton*) sender();
    expr = new TerminalExpression<double>((ui->display->text() + button->text()).toDouble());
    update_display();
}

void Calculator::unaryOperation_pressed()
{
    delete expr;
    QPushButton* button = (QPushButton*) sender();
    if (button->text() == "%") {
        expr = new PercentExpression<double>(new TerminalExpression<double>((ui->display->text()).toDouble()));
    } else if (button->text() == "x²") {
        expr = new SquareExpression<double>(new TerminalExpression<double>((ui->display->text()).toDouble()));
    } else if (button->text() == "√") {
        expr = new SqrtExpression<double>(new TerminalExpression<double>((ui->display->text()).toDouble()));
    } else if (button->text() == "SIN") {
        expr = new SinExpression<double>(new TerminalExpression<double>((ui->display->text()).toDouble()));
    } else if (button->text() == "COS") {
        expr = new CosExpression<double>(new TerminalExpression<double>((ui->display->text()).toDouble()));
    } else if (button->text() == "TAN") {
        expr = new TanExpression<double>(new TerminalExpression<double>((ui->display->text()).toDouble()));
    }
    update_display();
}

void Calculator::binaryOperation_pressed()
{

}

void Calculator::memoryOperation_pressed()
{
    QPushButton* button = (QPushButton*) sender();
    if (button->text() == "MC") {
        mem.MC(expr);
    } else if (button->text() == "MR") {
        delete expr;
        expr = new TerminalExpression<double>(mem.MR()->solve());
        update_display();
    }
}

void Calculator::on_btnDecimal_released()
{
    // !!!PENDING DULU TUNGGU GENERIC
    delete expr;
    expr = new TerminalExpression<double>((ui->display->text() + ".6").toDouble());
    update_display();
}

void Calculator::update_display()
{
    qDebug() << expr->solve();
    QString labelValue = QString::number(expr->solve(), 'g', 15);
    ui->display->setText(labelValue);
}

void Calculator::on_btnClearExpr_released()
{
    delete expr;
    expr = new TerminalExpression<double>(0);
    update_display();
}


void Calculator::on_btnClear_released()
{
    delete expr;
    expr = new TerminalExpression<double>(0);
    mem.clear();
    update_display();
}
