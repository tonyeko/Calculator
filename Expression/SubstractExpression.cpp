#include "SubstractExpression.hpp"

SubstractExpression::SubstractExpression(Expression* x, Expression* y) : BinaryExpression(x,y) {}

double SubstractExpression::solve() {
	return x->solve() - y->solve();	
}

