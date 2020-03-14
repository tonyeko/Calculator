#include "UnaryExpression.hpp"

UnaryExpression::UnaryExpression(Expression* x) {
    this->x = x;
}

UnaryExpression::~UnaryExpression() {
    delete x;
}