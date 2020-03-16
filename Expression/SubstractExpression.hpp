#ifndef SUBSTRACT_EXPRESSION_HPP_
#define SUBSTRACT_EXPRESSION_HPP_

#include "BinaryExpression.hpp"

template<class T>
class SubstractExpression : public BinaryExpression<T> {
	public:
		SubstractExpression(Expression<T>* x, Expression<T>* y);
		T solve();
};

#endif