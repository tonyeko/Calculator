#include "Expression.hpp"

class UnaryExpression : public Expression {
protected:
    Expression* x;
public:
    UnaryExpression(Expression* x);
    virtual double solve() = 0;
};