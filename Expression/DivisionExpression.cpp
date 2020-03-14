#include "DivisionExpression.hpp"

DivisionExpression::DivisionExpression(Expression *x, Expression *y) : BinaryExpression(x, y) {}

double DivisionExpression::solve() {
	return x->solve() / y->solve();	
}
