#ifndef __INVALIDOPERATOR_EXCEPTION_HPP__
#define __INVALIDOPERATOR_EXCEPTION_HPP__

#include "BaseException.hpp"
#include <iostream>
#include <string>
using namespace std;

class InvalidOperatorException : public BaseException {
public:
    InvalidOperatorException() {
        message = "KACAU";
    }
    string getMessage() {
        return message;
    }
};

#endif
