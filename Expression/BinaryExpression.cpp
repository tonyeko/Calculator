#include "BinaryExpression.hpp"

template<class T>
BinaryExpression<T>::BinaryExpression(Expression<T>* x, Expression<T>* y) {
    this->x = x;
    this->y = y;
}

template<class T>
BinaryExpression<T>::~BinaryExpression() {
    delete x;
    delete y;
}