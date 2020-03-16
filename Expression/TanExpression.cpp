#include "TanExpression.hpp"
#include <cmath>

template<class T>
TanExpression<T>::TanExpression(Expression<T>* x) : TrigonometryExpression<T>(x) {}

template<class T>
double TanExpression<T>::solve() {
	return tan(TrigonometryExpression<T>::x->solve());	
}