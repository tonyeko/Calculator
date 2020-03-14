#ifndef COS_EXPRESSION_HPP_
#define COS_EXPRESSION_HPP_

#include "TrigonometryExpression.hpp"

class CosExpression : public TrigonometryExpression {
	public:
		CosExpression(Expression* x);
		double solve();
};

#endif
