#include "UnaryExpression.hpp"

template<class T>
UnaryExpression<T>::UnaryExpression(Expression<T>* x) {
    this->x = x;
}

template<class T>
UnaryExpression<T>::~UnaryExpression() {
    delete x;
}