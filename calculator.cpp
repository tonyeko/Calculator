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
    expr = new TerminalExpression<QString>("");
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

void Calculator::setExpr(QString qStr)
{
    delete expr;
    expr = new TerminalExpression<QString>(qStr);
}

void Calculator::clearExpr()
{
    delete expr;
    expr = new TerminalExpression<QString>("");
}

double Calculator::getAns() {
    return ans;
}

void Calculator::number_pressed()
{
    QPushButton* button = (QPushButton*) sender();
    setExpr((expr->solve() + button->text()));
    update_display();
}

void Calculator::unaryOperation_pressed()
{
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

//    delete expr;
//    QPushButton* button = (QPushButton*) sender();
//    if (button->text() == "%") {
//        expr = new PercentExpression<double>(new TerminalExpression<double>((ui->display->text()).toDouble()));
//    } else if (button->text() == "x²") {
//        expr = new SquareExpression<double>(new TerminalExpression<double>((ui->display->text()).toDouble()));
//    } else if (button->text() == "√") {
//        expr = new SqrtExpression<double>(new TerminalExpression<double>((ui->display->text()).toDouble()));
//    } else if (button->text() == "SIN") {
//        expr = new SinExpression<double>(new TerminalExpression<double>((ui->display->text()).toDouble()));
//    } else if (button->text() == "COS") {
//        expr = new CosExpression<double>(new TerminalExpression<double>((ui->display->text()).toDouble()));
//    } else if (button->text() == "TAN") {
//        expr = new TanExpression<double>(new TerminalExpression<double>((ui->display->text()).toDouble()));
//    }
//    update_display();
}

void Calculator::binaryOperation_pressed()
{
	QPushButton* button = (QPushButton*) sender();
    setExpr((expr->solve() + button->text()));
    update_display();
//    if (button->text() == "+") {
//    	expr = new AddExpression<double>(new TerminalExpression<double>((ui->display->text()).toDouble()));
//    } else if (button->text() == "-") {
//    	expr = new SubstractExpression<double>(new TerminalExpression<double>((ui->display->text()).toDouble()));
//	  } else if (button->text() == "x") {
//    	expr = new MultiplicationExpression<double>(new TerminalExpression<double>((ui->display->text()).toDouble()));
//	  } else if (button->text() == "/") {
//    	expr = new DivisionExpression<double>(new TerminalExpression<double>((ui->display->text()).toDouble()));

}

void Calculator::memoryOperation_pressed()
{
    QPushButton* button = (QPushButton*) sender();
    if (button->text() == "MC") {
        // CEK VALID GA EXPRESI NYA
        mem.MC(new TerminalExpression<double>(expr->solve().toDouble()));
    } else if (button->text() == "MR") {
        delete expr;
        QString labelValue = QString::number(mem.MR()->solve(), 'g', 15);
        expr = new TerminalExpression<QString>(labelValue);
        update_display();
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
