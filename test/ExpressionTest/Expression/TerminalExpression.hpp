#ifndef TERMINAL_EXPRESSION_HPP_
#define TERMINAL_EXPRESSION_HPP_

#include "Expression.hpp"

template<class T>
class TerminalExpression : public Expression<T> {
protected:
    T x;
public:
    TerminalExpression(T x) {
    	this->x = x;
	}
	T solve() {
    	return this->x;
	}
};

#endif