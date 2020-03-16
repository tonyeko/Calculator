#ifndef SQUARE_EXPRESSION_HPP_
#define SQUARE_EXPRESSION_HPP_

#include "UnaryExpression.hpp"

template<class T>
class SquareExpression : public UnaryExpression<T> {
	public:
		SquareExpression(Expression<T>* x) : UnaryExpression<T>(x) {}
		double solve() {
			return UnaryExpression<T>::x->solve() * UnaryExpression<T>::x->solve();	
		}
};

#endif