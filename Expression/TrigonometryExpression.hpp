#ifndef TRIGONOMETRY_EXPRESSION_HPP_
#define TRIGONOMETRY_EXPRESSION_HPP_

#include "UnaryExpression.hpp"

class TrigonometryExpression : public UnaryExpression {
	public:
		TrigonometryExpression(Expression* x);
		virtual double solve() = 0;
};

#endif