#ifndef ADD_EXPRESSION_HPP_
#define ADD_EXPRESSION_HPP_

#include "BinaryExpression.hpp"

class AddExpression : public BinaryExpression {
	public:
		AddExpression(Expression *x, Expression *y);
		double solve();
};

#endif