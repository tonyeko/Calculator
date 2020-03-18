#ifndef DECIMAL_EXPRESSION_HPP_
#define DECIMAL_EXPRESSION_HPP_

#include "BinaryExpression.hpp"
#include <cmath>

template<class T, int length>
class DecimalExpression : public BinaryExpression<T> {
	public:
		DecimalExpression(Expression<T>* x, Expression<T>* y) : BinaryExpression<T>(x,y) {}
		T solve() {
			return BinaryExpression<T>::x->solve() + (BinaryExpression<T>::y->solve() / pow(10, length));
		}
};

#endif