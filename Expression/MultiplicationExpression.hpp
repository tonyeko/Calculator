#ifndef MULTIPLICATION_EXPRESSION_HPP_
#define MULTIPLICATION_EXPRESSION_HPP_

#include "BinaryExpression.hpp"

template<class T>
class MultiplicationExpression : public BinaryExpression<T> {
	public:
		MultiplicationExpression(Expression<T> *x, Expression<T> *y);
		T solve();
};

#endif