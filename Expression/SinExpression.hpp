#ifndef SIN_EXPRESSION_HPP_
#define SIN_EXPRESSION_HPP_

#include "TrigonometryExpression.hpp"

template<class T>
class SinExpression : public TrigonometryExpression<T> {
	public:
		SinExpression(Expression<T>* x);
		double solve();
};

#endif
