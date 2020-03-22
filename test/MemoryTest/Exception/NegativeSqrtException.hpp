#ifndef __NEGATIVESQRT_EXCEPTION_HPP__
#define __NEGATIVESQRT_EXCEPTION_HPP__

#include "BaseException.hpp"
#include <iostream>
#include <string>
using namespace std;

class NegativeSqrtException : public BaseException {
public:
    NegativeSqrtException() {
        message = "NEG SQRT";
    }
    string getMessage() {
        return message;
    }
};

#endif
