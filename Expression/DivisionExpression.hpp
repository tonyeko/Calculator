#ifndef DIVISION_EXPRESSION_HPP_
#define DIVISION_EXPRESSION_HPP_

#include "BinaryExpression.hpp"

template<class T>
class DivisionExpression : public BinaryExpression<T> {
	public:
		DivisionExpression(Expression<T> *x, Expression<T> *y);
		double solve();
};

#endif