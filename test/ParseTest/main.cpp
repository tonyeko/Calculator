#include "tst_parsetesting.h"
#include <gtest/gtest.h>
#include "../../src/Parser.hpp"
#include "../../src/Parser.cpp"
using namespace testing;

TEST(Parser,InputTest) {
    Parser test("");
    EXPECT_THROW(test.parseInput(),NullPointerException);
    Parser testwo("()");
    EXPECT_THROW(testwo.parseInput(),EmptyParenthesesException*);
    Parser testhree("%1"); //handle error persen
    EXPECT_THROW(testhree.parseInput(),InvalidExpressionException*);
    Parser testfour("~-1"); //handle error square root
    EXPECT_THROW(testfour.parseInput(),NegativeSqrtException*);
    Parser testfive("2-"); //handle error min end
    EXPECT_THROW(testfive.parseInput(),InvalidExpressionException*);
    Parser testsix("^2"); //handle error pangkat
    EXPECT_THROW(testsix.parseInput(),InvalidExpressionException*);
    Parser testseven("4SIN(3)"); //handle error trigonometri
    EXPECT_THROW(testseven.parseInput(),InvalidExpressionException*);
    Parser testeight("+2"); //handle error addition
    EXPECT_THROW(testeight.parseInput(),InvalidExpressionException*);
    Parser testnine("3+-4");
    EXPECT_NO_THROW(testnine.parseInput());
}

TEST(Parser,UnaryTest) {
    Parser test("1"); //placeholder
    EXPECT_THAT(-2,test.unaryOperationHandler(2,"-"));
    EXPECT_THAT(0.2,test.unaryOperationHandler(20,"percent"));
    EXPECT_THAT(2,test.unaryOperationHandler(4,"sqrt"));
    EXPECT_THAT(4,test.unaryOperationHandler(2,"square"));
    EXPECT_THAT(0,test.unaryOperationHandler(0,"sin"));
    EXPECT_THAT(1,test.unaryOperationHandler(0,"cos"));
    EXPECT_THAT(0,test.unaryOperationHandler(0,"tan"));
}

TEST(Parser,BinaryTest) {
    Parser test("1"); //placeholder
    EXPECT_THAT(6,test.binaryOperationHandler(4,2,"plus"));
    EXPECT_THAT(2,test.binaryOperationHandler(4,2,"subtract"));
    EXPECT_THAT(8,test.binaryOperationHandler(4,2,"multiply"));
    EXPECT_THAT(2,test.binaryOperationHandler(4,2,"divide"));
}

TEST(Parser,SolveTest) {
    Parser test("1+2x3"); //prioritas operator binary
    test.parseInput();
    EXPECT_THAT(7,test.solve());
    Parser testwo("(1+2)x3"); //pemakaian tanda kurung
    testwo.parseInput();
    EXPECT_THAT(9,testwo.solve());
    Parser testhree("~((4+4)x2)");//kombinasi binary dengan unary di depan
    testhree.parseInput();
    EXPECT_THAT(4,testhree.solve());
    Parser testfour("~((4+4)x2)^");//kombinasi binary dengan unary di depan dan belakang
    testfour.parseInput();
    EXPECT_THAT(16,testfour.solve());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
