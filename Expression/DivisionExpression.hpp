#ifndef DIVISION_EXPRESSION_HPP_
#define DIVISION_EXPRESSION_HPP_

#include "BinaryExpression.hpp"

class DivisionExpression : public BinaryExpression {
	public:
		DivisionExpression(Expression *x, Expression *y);
		double solve();
};

#endif