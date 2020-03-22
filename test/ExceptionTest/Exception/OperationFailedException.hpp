#ifndef __OPERATIONFAILED_EXCEPTION_HPP__
#define __OPERATIONFAILED_EXCEPTION_HPP__

#include "BaseException.hpp"
#include <iostream>
#include <string>
using namespace std;

class OperationFailedException : public BaseException {
	private:
		BaseException* exc;
	public:
		OperationFailedException(BaseException* exc) {
			this->exc = exc;
		}
		string getMessage() {
            message = "ERR: ";
            message += exc->getMessage();
            return message;
		}
};

#endif
