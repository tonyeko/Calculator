#include "CosExpression.hpp"
#include <cmath>

CosExpression::CosExpression(Expression* x) : TrigonometryExpression(x) {}

double CosExpression::solve() {
	return cos(x->solve());	
}
