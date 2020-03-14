#include "SquareExpression.hpp"

SquareExpression::SquareExpression(Expression* x) : UnaryExpression(x) {}

double SquareExpression::solve() {
	return x->solve() * x->solve();	
}
