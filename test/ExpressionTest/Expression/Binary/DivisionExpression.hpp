#ifndef DIVISION_EXPRESSION_HPP_
#define DIVISION_EXPRESSION_HPP_

#include "BinaryExpression.hpp"

template<class T>
class DivisionExpression : public BinaryExpression<T> {
	public:
		DivisionExpression(Expression<T> *x, Expression<T> *y) : BinaryExpression<T>(x, y) {}
		double solve() {
			return BinaryExpression<T>::x->solve() / BinaryExpression<T>::y->solve();	
		}
};

#endif