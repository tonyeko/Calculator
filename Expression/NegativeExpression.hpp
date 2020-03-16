#ifndef NEGATIVE_EXPRESSION_HPP_
#define NEGATIVE_EXPRESSION_HPP_

#include "UnaryExpression.hpp"

template<class T>
class NegativeExpression : public UnaryExpression<T> {
	public:
		NegativeExpression(Expression<T>* x) : UnaryExpression<T>(x) {}
		T solve() {
			return UnaryExpression<T>::x->solve() * -1;	
		}
};

#endif