#include "SubstractExpression.hpp"

template<class T>
SubstractExpression<T>::SubstractExpression(Expression<T>* x, Expression<T>* y) : BinaryExpression<T>(x,y) {}

template<class T>
T SubstractExpression<T>::solve() {
	return BinaryExpression<T>::x->solve() - BinaryExpression<T>::y->solve();	
}

