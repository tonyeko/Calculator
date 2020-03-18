#ifndef DECIMAL_EXPRESSION_HPP_
#define DECIMAL_EXPRESSION_HPP_

#include "UnaryExpression.hpp"
#include <cmath>

template<class T, int length>
class DecimalExpression : public UnaryExpression<T> {
	public:
		DecimalExpression(Expression<T>* x) : UnaryExpression<T>(x) {}
		T solve() {
			return UnaryExpression<T>::x->solve() / pow(10, length);
		}
};

#endif