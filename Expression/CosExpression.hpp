#ifndef COS_EXPRESSION_HPP_
#define COS_EXPRESSION_HPP_

#include "TrigonometryExpression.hpp"

template<class T>
class CosExpression : public TrigonometryExpression<T> {
	public:
		CosExpression(Expression<T>* x);
		double solve();
};

#endif