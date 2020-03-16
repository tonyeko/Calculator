#include "SquareExpression.hpp"

template<class T>
SquareExpression<T>::SquareExpression(Expression<T>* x) : UnaryExpression<T>(x) {}

template<class T>
double SquareExpression<T>::solve() {
	return UnaryExpression<T>::x->solve() * UnaryExpression<T>::x->solve();	
}
