#ifndef __NULLPOINTER_EXCEPTION_HPP__
#define __NULLPOINTER_EXCEPTION_HPP__

#include "BaseException.hpp"
#include <iostream>
#include <string>
using namespace std;

class NullPointerException : public BaseException {
public:
    NullPointerException() {
        message = "NULL";
    }
    string getMessage() {
        return message;
    }
};

#endif
