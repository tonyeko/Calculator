#include "BinaryExpression.hpp"

class SubstractExpression : public BinaryExpression {
	public:
		SubstractExpression(Expression* x, Expression* y);
		double solve();
};

