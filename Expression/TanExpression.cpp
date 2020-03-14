#include "TanExpression.hpp"
#include <cmath>

TanExpression::TanExpression(Expression* x) : TrigonometryExpression(x) {}

double TanExpression::solve() {
	return tan(x->solve());	
}
