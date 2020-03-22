#ifndef __DOUBLENEGATION_EXCEPTION_HPP__
#define __DOUBLENEGATION_EXCEPTION_HPP__

#include "BaseException.hpp"
#include <iostream>
#include <string>
using namespace std;

class DoubleNegationException : public BaseException {
public:
    DoubleNegationException() {
        message = "DOUBLE NEG";
    }
    string getMessage() {
        return message;
    }
};

#endif
