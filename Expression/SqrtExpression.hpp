#ifndef SQRT_EXPRESSION_HPP_
#define SQRT_EXPRESSION_HPP_

#include "UnaryExpression.hpp"

class SqrtExpression : public UnaryExpression {
	public:
		SqrtExpression(Expression* x);
		double solve();
};

#endif