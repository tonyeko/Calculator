#ifndef ADD_EXPRESSION_HPP
#define ADD_EXPRESSION_HPP

#include "BinaryExpression.hpp"

template<class T>
class AddExpression : public BinaryExpression<T> {
	public:
		AddExpression(Expression<T> *x, Expression<T> *y) : BinaryExpression<T>(x, y) {}
		T solve() {
			return BinaryExpression<T>::x->solve() + BinaryExpression<T>::y->solve();	
		}
};

#endif // ADD_EXPRESSION_HPP
