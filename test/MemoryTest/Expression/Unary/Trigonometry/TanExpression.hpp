#ifndef TAN_EXPRESSION_HPP_
#define TAN_EXPRESSION_HPP_

#include "TrigonometryExpression.hpp"
#include <cmath>

template<class T>
class TanExpression : public TrigonometryExpression<T> {
	public:
		TanExpression(Expression<T>* x) : TrigonometryExpression<T>(x) {}
		double solve() {
			return tan(TrigonometryExpression<T>::x->solve());	
		}
};

#endif