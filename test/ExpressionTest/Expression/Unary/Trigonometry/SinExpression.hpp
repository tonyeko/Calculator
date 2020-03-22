#ifndef SIN_EXPRESSION_HPP_
#define SIN_EXPRESSION_HPP_

#include "TrigonometryExpression.hpp"
#include <cmath>

template<class T>
class SinExpression : public TrigonometryExpression<T> {
	public:
		SinExpression(Expression<T>* x) : TrigonometryExpression<T>(x) {}
		double solve() {
			return sin(TrigonometryExpression<T>::x->solve());	
		}
};

#endif