#ifndef SQUARE_EXPRESSION_HPP_
#define SQUARE_EXPRESSION_HPP_

#include "UnaryExpression.hpp"

class SquareExpression : public UnaryExpression {
	public:
		SquareExpression(Expression* x);
		double solve();
};

#endif