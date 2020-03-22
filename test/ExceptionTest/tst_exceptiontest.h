#ifndef TST_EXCEPTIONTEST_H
#define TST_EXCEPTIONTEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "Exception/BaseException.hpp"
#include "Exception/DivideByZeroException.hpp"
#include "Exception/DoubleNegationException.hpp"
#include "Exception/EmptyParenthesesException.hpp"
#include "Exception/InvalidExpressionException.hpp"
#include "Exception/NegativeSqrtException.hpp"
#include "Exception/NullPointerException.hpp"
#include "Exception/OperationFailedException.hpp"

using namespace testing;
using namespace std;

BaseException *exc;

TEST(Exception, DivideByZeroException)
{
    exc = new DivideByZeroException();
    EXPECT_EQ(exc->getMessage(), "DIV BY ZERO");
}

TEST(Exception, DoubleNegationException)
{
    exc = new DoubleNegationException();
    EXPECT_EQ(exc->getMessage(), "DOUBLE NEG");
}

TEST(Exception, EmptyParenthesesException)
{
    exc = new EmptyParenthesesException();
    EXPECT_EQ(exc->getMessage(), "EMPTY ()");
}

TEST(Exception, InvalidExpressionException)
{
    string err = "EMPTY";
    exc = new InvalidExpressionException(err);
    EXPECT_EQ(exc->getMessage(), err);
}

TEST(Exception, NegativeSqrtException)
{
    exc = new NegativeSqrtException();
    EXPECT_EQ(exc->getMessage(), "NEG SQRT");
}

TEST(Exception, NullPointerException)
{
    exc = new NullPointerException();
    EXPECT_EQ(exc->getMessage(), "NULL");
}

TEST(Exception, OperationFailedException)
{
    exc = new OperationFailedException(new NullPointerException());
    string comp = "ERR: NULL";
    EXPECT_EQ(exc->getMessage(), comp);
}
#endif // TST_EXCEPTIONTEST_H
