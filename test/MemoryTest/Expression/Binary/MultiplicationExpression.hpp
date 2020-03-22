#ifndef MULTIPLICATION_EXPRESSION_HPP_
#define MULTIPLICATION_EXPRESSION_HPP_

#include "BinaryExpression.hpp"

template<class T>
class MultiplicationExpression : public BinaryExpression<T> {
	public:
		MultiplicationExpression(Expression<T> *x, Expression<T> *y) : BinaryExpression<T>(x, y) {}
		T solve() {
			return BinaryExpression<T>::x->solve() * BinaryExpression<T>::y->solve();	
		}
};

#endif