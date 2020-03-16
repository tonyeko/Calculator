#ifndef __BASE_EXCEPTION_HPP__
#define __BASE_EXCEPTION_HPP__

#include <string>

class BaseException {
    protected:
        string message;
    public:
        // menuliskan pesan kesalahan ke stdout
        virtual string getMessage() = 0;
};

#endif