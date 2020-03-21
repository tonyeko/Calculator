// Data.hpp
// Contributor : 13518135
/*  Includes string parser
    Stores temp data
*/

#ifndef DATA_HPP
#define DATA_HPP
#include <iostream>
#include <utility>
#include <vector>
#include "Exception/NullPointerException.hpp"
#include "Exception/InvalidExpressionException.hpp"
#include "Exception/DoubleNegationException.hpp"
#include "Exception/DivideByZeroException.hpp"
#include "Exception/EmptyParenthesesException.hpp"
#include "Exception/NegativeSqrtException.hpp"
#include "Expression/Expression.hpp"
#include "Expression/TerminalExpression.hpp"
#include "Expression/Unary/NegativeExpression.hpp"
#include "Expression/Unary/PercentExpression.hpp"
#include "Expression/Unary/SqrtExpression.hpp"
#include "Expression/Unary/SquareExpression.hpp"
#include "Expression/Unary/Trigonometry/SinExpression.hpp"
#include "Expression/Unary/Trigonometry/CosExpression.hpp"
#include "Expression/Unary/Trigonometry/TanExpression.hpp"
#include "Expression/Binary/AddExpression.hpp"
#include "Expression/Binary/SubtractExpression.hpp"
#include "Expression/Binary/DecimalExpression.hpp"
#include "Expression/Binary/MultiplicationExpression.hpp"
#include "Expression/Binary/DivisionExpression.hpp"
using namespace std;

class Data {
protected: 
    // First: value, Second:type
    vector<pair<double,string>> vecData; //isi:token
    string input; // to parse
public:
    Data(string inp);
    void parseInput();
    double unaryOperationHandler(double val, string op);
    double binaryOperationHandler(double valfirst, double valsec, string op);
    void inputOp(bool &percent,double &val, string &type, string input);
    void debugData();
    double solve();
};


#endif // Data.hpp