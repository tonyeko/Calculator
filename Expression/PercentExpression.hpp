#ifndef PERCENT_EXPRESSION_HPP_
#define PERCENT_EXPRESSION_HPP_

#include "UnaryExpression.hpp"

class PercentExpression : public UnaryExpression {
	public:
		PercentExpression(Expression* x);
		double solve();
};

#endif