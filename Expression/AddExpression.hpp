#ifndef ADD_EXPRESSION_HPP_
#define ADD_EXPRESSION_HPP_

#include "BinaryExpression.hpp"

template<class T>
class AddExpression : public BinaryExpression<T> {
	public:
		AddExpression(Expression<T> *x, Expression<T> *y);
		T solve();
};

#endif