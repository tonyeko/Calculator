#ifndef MULTIPLICATION_EXPRESSION_HPP_
#define MULTIPLICATION_EXPRESSION_HPP_

#include "BinaryExpression.hpp"

class MultiplicationExpression : public BinaryExpression {
	public:
		MultiplicationExpression(Expression *x, Expression *y);
		double solve();
};

#endif