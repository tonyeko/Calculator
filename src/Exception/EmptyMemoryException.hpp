#ifndef __EMPTYMEMORY_EXCEPTION_HPP__
#define __EMPTYMEMORY_EXCEPTION_HPP__

#include "BaseException.hpp"
#include <iostream>
#include <string>
using namespace std;

class EmptyMemoryException : public BaseException {
public:
    EmptyMemoryException() {
        message = "EMP MEM";
    }
    string getMessage() {
        return message;
    }
};

#endif
