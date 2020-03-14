#include "Memory.hpp"
#include <iostream>
using namespace std;

void Memory::MC(Expression* x) {
    Mem.push(x);
}

Expression* Memory::MR() {
    Expression* x = Mem.front();
    Mem.pop();
    return x;
}

void Memory::clear() {
    while (!Mem.empty()) {
        Mem.pop();
    }
    
}