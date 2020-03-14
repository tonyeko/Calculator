#include "UnaryExpression.hpp"

class NegativeExpression : public UnaryExpression {
	public:
		NegativeExpression(Expression* x);
		double solve();
};

