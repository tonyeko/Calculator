#include "MultiplicationExpression.hpp"

template<class T>
MultiplicationExpression<T>::MultiplicationExpression(Expression<T> *x, Expression<T> *y) : BinaryExpression<T>(x, y) {}

template<class T>
T MultiplicationExpression<T>::solve() {
	return BinaryExpression<T>::x->solve() * BinaryExpression<T>::y->solve();	
}
