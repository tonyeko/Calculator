#ifndef SUBTRACT_EXPRESSION_HPP_
#define SUBTRACT_EXPRESSION_HPP_

#include "BinaryExpression.hpp"

template<class T>
class SubtractExpression : public BinaryExpression<T> {
	public:
		SubtractExpression(Expression<T>* x, Expression<T>* y) : BinaryExpression<T>(x,y) {}
		T solve() {
			return BinaryExpression<T>::x->solve() - BinaryExpression<T>::y->solve();	
		}
};

#endif