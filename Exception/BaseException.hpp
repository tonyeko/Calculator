#ifndef __BASE_EXCEPTION_HPP__
#define __BASE_EXCEPTION_HPP__

#include <string>
using namespace std;

class BaseException {
    protected:
        string message;
    public:
        virtual string getMessage() = 0;
};

#endif
