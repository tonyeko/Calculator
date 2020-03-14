#include "NegativeExpression.hpp"

NegativeExpression::NegativeExpression(Expression* x) : UnaryExpression(x) {}

double NegativeExpression::solve() {
	return x->solve() * -1;	
}
