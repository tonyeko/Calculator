#ifndef SUBSTRACT_EXPRESSION_HPP_
#define SUBSTRACT_EXPRESSION_HPP_

#include "BinaryExpression.hpp"

template<class T>
class SubstractExpression : public BinaryExpression<T> {
	public:
		SubstractExpression(Expression<T>* x, Expression<T>* y) : BinaryExpression<T>(x,y) {}
		T solve() {
			return BinaryExpression<T>::x->solve() - BinaryExpression<T>::y->solve();	
		}
};

#endif