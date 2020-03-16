#ifndef MEMORY_HPP_
#define MEMORY_HPP_

#include "TerminalExpression.hpp"
#include <queue>
using namespace std;

template<class T>
class Memory {
	private:
        queue<Expression<T>*> data;
	public:
		Memory() {};
		void MC(Expression<T>* x) {
    		data.push(new TerminalExpression<T>(x->solve()));
		}
		Expression<T>* MR() {
    		if (data.empty()) {
        		// IF IS EMPTY THROW EXCEPTION
    		}
    		Expression<T>* x = data.front();
    		data.pop();
    		return x;
		}
		void clear() {
    		while (!data.empty()) {
        		data.pop();
    		}
		}
};

#endif
