#ifndef BINARY_EXPRESSION_HPP_
#define BINARY_EXPRESSION_HPP_

#include "Expression.hpp"

template<class T>
class BinaryExpression : public Expression<T> {
protected:
    Expression<T>* x;
    Expression<T>* y;
public:
    BinaryExpression(Expression<T>* x, Expression<T>* y) {
    		this->x = x;
    		this->y = y;
	}
	virtual ~BinaryExpression() {
    		delete x;
    		delete y;
	}
	virtual T solve() = 0;
};

#endif
