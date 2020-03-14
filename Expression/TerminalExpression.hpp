#include "Expression.hpp"

class TerminalExpression : public Expression {
protected:
    double x;
public:
    TerminalExpression(double x);
    double solve();
};