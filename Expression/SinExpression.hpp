#ifndef SIN_EXPRESSION_HPP_
#define SIN_EXPRESSION_HPP_

#include "TrigonometryExpression.hpp"

class SinExpression : public TrigonometryExpression {
	public:
		SinExpression(Expression* x);
		double solve();
};

#endif
