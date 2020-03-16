#include "TerminalExpression.hpp"

template<class T>
TerminalExpression<T>::TerminalExpression(T x) {
    this->x = x;
}

template<class T>
T TerminalExpression<T>::solve() {
    return this->x;
}