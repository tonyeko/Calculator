#include "SinExpression.hpp"
#include <cmath>

template<class T>
SinExpression<T>::SinExpression(Expression<T>* x) : TrigonometryExpression<T>(x) {}

template<class T>
double SinExpression<T>::solve() {
	return sin(TrigonometryExpression<T>::x->solve());	
}