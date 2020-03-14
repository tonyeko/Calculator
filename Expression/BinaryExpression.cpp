#include "BinaryExpression.hpp"

BinaryExpression::BinaryExpression(Expression* x, Expression* y) {
    this->x = x;
    this->y = y;
}

BinaryExpression::~BinaryExpression() {
    delete x;
    delete y;
}