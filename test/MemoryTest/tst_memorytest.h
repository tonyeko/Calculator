#ifndef TST_MEMORYTEST_H
#define TST_MEMORYTEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "Expression/Memory.hpp"
#include "Expression/Expression.hpp"
#include "Expression/TerminalExpression.hpp"
using namespace testing;

Memory<double> m;

TEST(Memory, PushMemoryTest)
{
    for (int i = 0; i < 10; i++) {
        m.MC(new TerminalExpression<double>(i+1));
    }
    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(m.MR()->solve(), i+1);
    }
}

TEST(Memory, PopMemoryTest)
{
    EXPECT_THROW(m.MR(), BaseException*);
}

#endif // TST_MEMORYTEST_H
