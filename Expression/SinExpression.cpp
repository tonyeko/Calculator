#include "SinExpression.hpp"
#include <cmath>

SinExpression::SinExpression(Expression* x) : TrigonometryExpression(x) {}

double SinExpression::solve() {
	return sin(x->solve());	
}
