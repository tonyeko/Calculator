#include "PercentExpression.hpp"

template<class T>
PercentExpression<T>::PercentExpression(Expression<T>* x) : UnaryExpression<T>(x) {}

template<class T>
T PercentExpression<T>::solve() {
	return UnaryExpression<T>::x->solve() / 100;	
}
