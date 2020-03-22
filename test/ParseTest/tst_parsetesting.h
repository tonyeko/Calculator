#ifndef TST_PARSETESTING_H
#define TST_PARSETESTING_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST(Parse, ParseTesting)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

#endif // TST_PARSETESTING_H
