#include "Memory.hpp"
#include "TerminalExpression.hpp"
#include <iostream>
using namespace std;

template<class T>
void Memory<T>::MC(Expression<T>* x) {
    data.push(new TerminalExpression<T>(x->solve()));
}

template<class T>
Expression<T>* Memory<T>::MR() {
    if (data.empty()) {
        // IF IS EMPTY THROW EXCEPTION
    }
    Expression<T>* x = data.front();
    data.pop();
    return x;
}

template<class T>
void Memory<T>::clear() {
    while (!data.empty()) {
        data.pop();
    }
}
