#ifndef TST_EXPRESSIONTEST_H
#define TST_EXPRESSIONTEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <string>
#include "Expression/Expression.hpp"
#include "Expression/TerminalExpression.hpp"
#include "Expression/Unary/NegativeExpression.hpp"
#include "Expression/Unary/PercentExpression.hpp"
#include "Expression/Unary/SqrtExpression.hpp"
#include "Expression/Unary/SquareExpression.hpp"
#include "Expression/Unary/Trigonometry/SinExpression.hpp"
#include "Expression/Unary/Trigonometry/CosExpression.hpp"
#include "Expression/Unary/Trigonometry/TanExpression.hpp"
#include "Expression/Binary/AddExpression.hpp"
#include "Expression/Binary/DivisionExpression.hpp"
#include "Expression/Binary/MultiplicationExpression.hpp"
#include "Expression/Binary/SubtractExpression.hpp"

using namespace testing;
using namespace std;

Expression<double>* e1 = new TerminalExpression<double>(20);
Expression<double>* e2 = new TerminalExpression<double>(4);

TEST(Expression, TerminalExpressionDoubleTest)
{
    Expression<double>* e = new TerminalExpression<double>(6);
    ASSERT_THAT(e->solve(), Eq(6));
}

TEST(Expression, TerminalExpressionStringTest)
{
    Expression<string>* e = new TerminalExpression<string>("tes");
    ASSERT_THAT(e->solve(), Eq("tes"));
}

TEST(Expression, NegativeExpressionTest)
{
    Expression<double>* e = new NegativeExpression<double>(new TerminalExpression<double>(6));
    ASSERT_THAT(e->solve(), Eq(-6));
}

TEST(Expression, PercentExpressionTest)
{
    Expression<double>* e = new PercentExpression<double>(new TerminalExpression<double>(6));
    ASSERT_THAT(e->solve(), Eq(0.06));
}

TEST(Expression, SqrtExpressionTest)
{
    Expression<double>* e = new SqrtExpression<double>(new TerminalExpression<double>(4));
    ASSERT_THAT(e->solve(), Eq(2));
}

TEST(Expression, SquareExpressionTest)
{
    Expression<double>* e = new SquareExpression<double>(new TerminalExpression<double>(6));
    ASSERT_THAT(e->solve(), Eq(36));
}

TEST(Expression, AddExpressionTest)
{
    Expression<double>* e = new AddExpression<double>(e1, e2);
    ASSERT_THAT(e->solve(), Eq(24));
}

TEST(Expression, SubtractExpressionTest)
{
    Expression<double>* e = new SubtractExpression<double>(e1, e2);
    ASSERT_THAT(e->solve(), Eq(16));
}


TEST(Expression, MultiplicationExpressionTest)
{
    Expression<double>* e = new MultiplicationExpression<double>(e1, e2);
    ASSERT_THAT(e->solve(), Eq(80));
}

TEST(Expression, DivisionExpressionTest)
{
    Expression<double>* e = new DivisionExpression<double>(e1, e2);
    ASSERT_THAT(e->solve(), Eq(5));
}

#endif // TST_EXPRESSIONTEST_H
