#include "SqrtExpression.hpp"
#include <cmath>

SqrtExpression::SqrtExpression(Expression* x) : UnaryExpression(x) {}

double SqrtExpression::solve() {
	return sqrt(x->solve());	
}
