#ifndef _EXPRESSION_HPP_
#define _EXPRESSION_HPP_

template <class T>
class Expression {
public:
    Expression() {}
    virtual ~Expression() {}
    virtual T solve();
};

#endif