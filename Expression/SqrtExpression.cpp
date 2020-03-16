#include "SqrtExpression.hpp"
#include <cmath>

template<class T>
SqrtExpression<T>::SqrtExpression(Expression<T>* x) : UnaryExpression<T>(x) {}

template<class T>
double SqrtExpression<T>::solve() {
	return sqrt(UnaryExpression<T>::x->solve());	
}