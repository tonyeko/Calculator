#ifndef TRIGONOMETRY_EXPRESSION_HPP_
#define TRIGONOMETRY_EXPRESSION_HPP_

#include "UnaryExpression.hpp"

template<class T>
class TrigonometryExpression : public UnaryExpression<T> {
	public:
		TrigonometryExpression(Expression<T>* x) : UnaryExpression<T>(x) {}
		virtual T solve();
};

#endif