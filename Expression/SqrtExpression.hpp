#ifndef SQRT_EXPRESSION_HPP_
#define SQRT_EXPRESSION_HPP_

#include "UnaryExpression.hpp"

template<class T>
class SqrtExpression : public UnaryExpression<T> {
	public:
		SqrtExpression(Expression<T>* x);
		double solve();
};

#endif