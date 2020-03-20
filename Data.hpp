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
#include <stack>
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
    void inputOp(bool &percent, bool &foundDecimal, double &val, string &type, string input);
    void debugData();
    void solve();
};


#endif // Data.hpp