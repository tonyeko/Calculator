#ifndef SQRT_EXPRESSION_HPP_
#define SQRT_EXPRESSION_HPP_

#include "UnaryExpression.hpp"
#include <cmath>

template<class T>
class SqrtExpression : public UnaryExpression<T> {
	public:
		SqrtExpression(Expression<T>* x) : UnaryExpression<T>(x) {}
		double solve() {
			return sqrt(UnaryExpression<T>::x->solve());	
		}
};

#endif