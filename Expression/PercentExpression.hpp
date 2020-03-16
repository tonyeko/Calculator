#ifndef PERCENT_EXPRESSION_HPP_
#define PERCENT_EXPRESSION_HPP_

#include "UnaryExpression.hpp"

template<class T>
class PercentExpression : public UnaryExpression<T> {
	public:
		PercentExpression(Expression<T>* x);
		T solve();
};

#endif