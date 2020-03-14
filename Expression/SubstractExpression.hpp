#ifndef SUBSTRACT_EXPRESSION_HPP_
#define SUBSTRACT_EXPRESSION_HPP_

#include "BinaryExpression.hpp"

class SubstractExpression : public BinaryExpression {
	public:
		SubstractExpression(Expression* x, Expression* y);
		double solve();
};

#endif