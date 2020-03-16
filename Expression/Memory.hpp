#ifndef MEMORY_HPP_
#define MEMORY_HPP_

#include "Expression.hpp"
#include <queue>
using namespace std;

template<class T>
class Memory {
	private:
        queue<Expression<T>*> data;
	public:
		Memory() {};
		void MC(Expression<T>* x);
		Expression<T>* MR();
		void clear();
};

#endif
