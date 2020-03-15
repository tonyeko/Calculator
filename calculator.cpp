#include "calculator.h"
#include "ui_calculator.h"
#include "Expression/Expression.hpp"
#include "Expression/TerminalExpression.hpp"
#include "Expression/UnaryExpression.hpp"
#include "Expression/BinaryExpression.hpp"

#include <QtDebug>

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
    expr = new TerminalExpression(0);
    connect(ui->pushButton_00, SIGNAL(released()), this, SLOT(number_pressed()));
    connect(ui->pushButton_0, SIGNAL(released()), this, SLOT(number_pressed()));
    connect(ui->pushButton_1, SIGNAL(released()), this, SLOT(number_pressed()));
    connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(number_pressed()));
    connect(ui->pushButton_3, SIGNAL(released()), this, SLOT(number_pressed()));
    connect(ui->pushButton_4, SIGNAL(released()), this, SLOT(number_pressed()));
    connect(ui->pushButton_5, SIGNAL(released()), this, SLOT(number_pressed()));
    connect(ui->pushButton_6, SIGNAL(released()), this, SLOT(number_pressed()));
    connect(ui->pushButton_7, SIGNAL(released()), this, SLOT(number_pressed()));
    connect(ui->pushButton_8, SIGNAL(released()), this, SLOT(number_pressed()));
    connect(ui->pushButton_9, SIGNAL(released()), this, SLOT(number_pressed()));
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::number_pressed()
{
    QPushButton* button = (QPushButton*) sender();
    delete expr;
    expr = new TerminalExpression((ui->label->text() + button->text()).toDouble());
    qDebug() << expr->solve();
    QString labelValue = QString::number(expr->solve(), 'g', 15);
    ui->label->setText(labelValue);
    qDebug() << labelValue;

}

void Calculator::on_decimalButton_released()
{

}
