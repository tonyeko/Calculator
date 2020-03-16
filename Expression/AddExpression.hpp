#ifndef ADD_EXPRESSION_HPP_
#define ADD_EXPRESSION_HPP_

#include "BinaryExpression.hpp"

template<class T>
class AddExpression : public BinaryExpression<T> {
	public:
		AddExpression(Expression<T> *x, Expression<T> *y) : BinaryExpression<T>(x,y) {}
		T solve() {
				return BinaryExpression<T>::x->solve() + BinaryExpression<T>::y->solve();	
		}
};

#endif