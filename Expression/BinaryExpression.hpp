#include "Expression.hpp"

class BinaryExpression : public Expression {
protected:
    Expression* x;
    Expression* y;
public:
    BinaryExpression(Expression* x, Expression* y);
    virtual double solve() = 0;
};