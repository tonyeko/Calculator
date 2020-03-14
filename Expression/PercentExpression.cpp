#include "PercentExpression.hpp"

PercentExpression::PercentExpression(Expression* x) : UnaryExpression(x) {}

double PercentExpression::solve() {
	return x->solve() / 100;	
}
