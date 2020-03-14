#ifndef UNARY_EXPRESSION_HPP_
#define UNARY_EXPRESSION_HPP_

#include "Expression.hpp"

class UnaryExpression : public Expression {
protected:
    Expression* x;
public:
    UnaryExpression(Expression* x);
    virtual ~UnaryExpression();
    virtual double solve() = 0;
};

#endif