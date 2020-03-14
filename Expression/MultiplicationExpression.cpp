#include "MultiplicationExpression.hpp"

MultiplicationExpression::MultiplicationExpression(Expression *x, Expression *y) : BinaryExpression(x, y) {}

double MultiplicationExpression::solve() {
	return x->solve() * y->solve();	
}
