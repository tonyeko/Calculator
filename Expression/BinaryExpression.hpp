#ifndef BINARY_EXPRESSION_HPP_
#define BINARY_EXPRESSION_HPP_

#include "Expression.hpp"

class BinaryExpression : public Expression {
protected:
    Expression* x;
    Expression* y;
public:
    BinaryExpression(Expression* x, Expression* y);
    virtual ~BinaryExpression();
    virtual double solve() = 0;
};

#endif