#include "CosExpression.hpp"
#include <cmath>

template<class T>
CosExpression<T>::CosExpression(Expression<T>* x) : TrigonometryExpression<T>(x) {}

template<class T>
double CosExpression<T>::solve() {
	return cos(TrigonometryExpression<T>::x->solve());	
}