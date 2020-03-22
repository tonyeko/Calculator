#ifndef PERCENT_EXPRESSION_HPP_
#define PERCENT_EXPRESSION_HPP_

#include "UnaryExpression.hpp"

template<class T>
class PercentExpression : public UnaryExpression<T> {
	public:
		PercentExpression(Expression<T>* x) : UnaryExpression<T>(x) {}
		double solve() {
			return UnaryExpression<T>::x->solve() / 100;	
		}
};

#endif