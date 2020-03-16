#ifndef TAN_EXPRESSION_HPP_
#define TAN_EXPRESSION_HPP_

#include "TrigonometryExpression.hpp"

template<class T>
class TanExpression : public TrigonometryExpression<T> {
	public:
		TanExpression(Expression<T>* x);
		double solve();
};

#endif