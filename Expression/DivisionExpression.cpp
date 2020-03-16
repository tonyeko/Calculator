#include "DivisionExpression.hpp"

template<class T>
DivisionExpression<T>::DivisionExpression(Expression<T> *x, Expression<T> *y) : BinaryExpression<T>(x, y) {}

template<class T>
double DivisionExpression<T>::solve() {
	return BinaryExpression<T>::x->solve() / BinaryExpression<T>::y->solve();	
}
