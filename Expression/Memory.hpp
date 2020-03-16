#ifndef MEMORY_HPP_
#define MEMORY_HPP_

#include "Expression.hpp"
#include <queue>
using namespace std;

class Memory {
	private:
        queue<Expression*> data;
	public:
		Memory() {};
		void MC(Expression* x);
		Expression* MR();
		void clear();
};

#endif
