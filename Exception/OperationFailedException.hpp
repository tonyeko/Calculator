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
            message = "Error: ";
			exc->getMessage();
		}
};