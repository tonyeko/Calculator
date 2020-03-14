#ifndef NEGATIVE_EXPRESSION_HPP_
#define NEGATIVE_EXPRESSION_HPP_

#include "UnaryExpression.hpp"

class NegativeExpression : public UnaryExpression {
	public:
		NegativeExpression(Expression* x);
		double solve();
};

#endif