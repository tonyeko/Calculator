#include "Memory.hpp"
#include "TerminalExpression.hpp"
#include <iostream>
using namespace std;

void Memory::MC(Expression* x) {
    data.push(new TerminalExpression(x->solve()));
}

Expression* Memory::MR() {
    if (data.empty()) {
        // IF IS EMPTY THROW EXCEPTION
    }
    Expression* x = data.front();
    data.pop();
    return x;
}

void Memory::clear() {
    while (!data.empty()) {
        data.pop();
    }
}
