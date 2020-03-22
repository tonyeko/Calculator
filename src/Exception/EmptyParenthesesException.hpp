#ifndef __EMPTYPARENTHESES_EXCEPTION_HPP__
#define __EMPTYPARENTHESES_EXCEPTION_HPP__

#include "BaseException.hpp"
#include <iostream>
#include <string>
using namespace std;

class EmptyParenthesesException : public BaseException {
public:
    EmptyParenthesesException() {
        message = "EMPTY ()";
    }
    string getMessage() {
        return message;
    }
};

#endif
