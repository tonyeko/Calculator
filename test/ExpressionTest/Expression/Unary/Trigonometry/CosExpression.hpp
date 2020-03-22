#ifndef COS_EXPRESSION_HPP_
#define COS_EXPRESSION_HPP_

#include "TrigonometryExpression.hpp"
#include <cmath>

template<class T>
class CosExpression : public TrigonometryExpression<T> {
	public:
		CosExpression(Expression<T>* x) : TrigonometryExpression<T>(x) {}
		double solve() {
			return cos(TrigonometryExpression<T>::x->solve());	
		}
};

#endif