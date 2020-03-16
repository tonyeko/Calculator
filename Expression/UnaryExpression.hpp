#ifndef UNARY_EXPRESSION_HPP_
#define UNARY_EXPRESSION_HPP_

#include "Expression.hpp"

template<class T>
class UnaryExpression : public Expression<T> {
protected:
    Expression<T>* x;
public:
    UnaryExpression(Expression<T>* x) {
    	this->x = x;
	}
	virtual ~UnaryExpression() {
    delete x;
	}
    virtual T solve();
};

#endif