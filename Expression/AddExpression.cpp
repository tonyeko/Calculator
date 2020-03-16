#include "AddExpression.hpp"

template<class T>
AddExpression<T>::AddExpression(Expression<T> *x, Expression<T> *y) : BinaryExpression<T>(x,y) {
}

template<class T>
T AddExpression<T>::solve() {
	return BinaryExpression<T>::x->solve() + BinaryExpression<T>::y->solve();	
}
