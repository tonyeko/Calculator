#ifndef __DIVIDEBYZERO_EXCEPTION_HPP__
#define __DIVIDEBYZERO_EXCEPTION_HPP__

#include "BaseException.hpp"
#include <iostream>
#include <string>
using namespace std;

class DivideByZeroException : public BaseException {
public:
    DivideByZeroException() {
        message = "DIV BY ZERO";
    }
    string getMessage() {
        return message;
    }
};

#endif
