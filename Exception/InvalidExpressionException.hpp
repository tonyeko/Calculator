#ifndef __INVALIDEXPRESSION_EXCEPTION_HPP__
#define __INVALIDEXPRESSION_EXCEPTION_HPP__

#include "BaseException.hpp"
#include <iostream>
#include <string>
using namespace std;

class InvalidExpressionException : public BaseException {
public:
    InvalidExpressionException(string expr) {
        message = "NOT VALID";
    }
    string getMessage() {
        return message;
    }
};

#endif
