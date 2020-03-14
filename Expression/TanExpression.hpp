#ifndef TAN_EXPRESSION_HPP_
#define TAN_EXPRESSION_HPP_

#include "TrigonometryExpression.hpp"

class TanExpression : public TrigonometryExpression {
	public:
		TanExpression(Expression* x);
		double solve();
};

#endif
