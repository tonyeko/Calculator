#ifndef _EXPRESSION_HPP_
#define _EXPRESSION_HPP_

class Expression {
public:
    Expression() {}
    virtual ~Expression() {}
    virtual double solve() = 0;
};

#endif
