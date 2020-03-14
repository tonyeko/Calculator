#include "BinaryExpression.hpp"

class AddExpression : public BinaryExpression {
	public:
		AddExpression(Expression *x, Expression *y);
		double solve();
};

