#ifndef DECIMAL_EXPRESSION_HPP_
#define DECIMAL_EXPRESSION_HPP_

#include "BinaryExpression.hpp"
#include <cmath>
using namespace std;

template<class T>
class DecimalExpression : public BinaryExpression<T> {
	private:
		int length;
	public:
		DecimalExpression(Expression<T>* x, Expression<T>* y, int length) : BinaryExpression<T>(x,y) {
			this->length = length;
		}
		double solve() {
			return BinaryExpression<T>::x->solve() + (BinaryExpression<T>::y->solve() / pow(10, this->length));
		}
};

#endif