#include "BaseException.hpp"
#include <iostream>
#include <string>
using namespace std;

class InvalidExpressionException : public BaseException {
private:
    string expr;
public:
    InvalidExpressionException(string expr) {
        this->expr = expr;
        message += "Ekspresi " + expr + " tidak valid\n";
    }
    string getMessage() {
        return message;
    }
};