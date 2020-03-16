#ifndef __NEGATIVESQRT_EXCEPTION_HPP__
#define __NEGATIVESQRT_EXCEPTION_HPP__

#include "BaseException.hpp"
#include <iostream>
#include <string>
using namespace std;

class NegativeSqrtException : public BaseException {
public:
    NegativeSqrtException() {
        message = "NEG SQRT\n";
    }
    string getMessage() {
        return message;
    }
};

#endif
