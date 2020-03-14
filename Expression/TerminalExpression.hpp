#ifndef TERMINAL_EXPRESSION_HPP_
#define TERMINAL_EXPRESSION_HPP_

#include "Expression.hpp"

class TerminalExpression : public Expression {
protected:
    double x;
public:
    TerminalExpression(double x);
    double solve();
};

#endif