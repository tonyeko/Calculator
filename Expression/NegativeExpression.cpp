#include "NegativeExpression.hpp"

template<class T>
NegativeExpression<T>::NegativeExpression(Expression<T>* x) : UnaryExpression<T>(x) {}

template<class T>
T NegativeExpression<T>::solve() {
	return UnaryExpression<T>::x->solve() * -1;	
}
