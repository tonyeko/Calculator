#ifndef __DIGITLIMIT_EXCEPTION_HPP__
#define __DIGITLIMIT_EXCEPTION_HPP__

#include "BaseException.hpp"
#include <iostream>
#include <string>
using namespace std;

class DigitLimitException : public BaseException {
public:
    DigitLimitException() {
        message = "EXPR > 14";
    }
    string getMessage() {
        return message;
    }
};

#endif
