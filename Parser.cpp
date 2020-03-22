// Parser.cpp
// Contributor : 13518135, 13518030, 13518105
/*  Implementasi Data.hpp
*/

#include "Parser.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

Parser::Parser(string inp) {
    input = inp;
}

void Parser::inputOp(bool &percent, double &val, string &type, string input) {
    percent = false;
    vecData.push_back(make_pair(val,type)); // push angka
    val = 0;
    type = input;
    vecData.push_back(make_pair(0,type)); //push operator
}

void Parser::parseInput() {
    if (input.empty()) throw NullPointerException();    
    else
    {   
        bool neg = false;
        bool percent = false;
        double value = 0;
        double dec = 0.0;
        double decCount = 10;
        string type = "null";
        string::iterator it;
        for (it=input.begin(); it!=input.end(); it++) {
            switch(*it) {
                // * Operators
                case '+':
                    if (type == "num" || type == "percent" || type == "close" || type == "square") inputOp(percent,value,type,"plus");
                    else if (type == "subtract" || type == "multiply" || type=="open") type = "num";
                    else throw new InvalidExpressionException("ADD");
                    break;
                case '-':
                    if (type == "subtract") throw new DoubleNegationException();
                    else if (type == "num" || type=="close" || type=="percent" || type=="square") inputOp(percent,value,type,"subtract");
                    else if (type == "sqrt") {
                        throw new NegativeSqrtException();
                    }
                    else {
                        type = "subtract";
                        neg = true;
                    } // throw InvalidExpressionException();
                    break;
                case 'x':
                    if (type == "num" || type=="close" || type == "square"|| type == "percent") inputOp(percent,value,type,"multiply");
                    else throw new InvalidExpressionException("MULTIPLY");
                    break;
                case '/': // divide by 0 dihandle solve
                    if (type == "num" || type=="close" || type == "square"|| type == "percent") inputOp(percent,value,type,"divide");
                    else throw new InvalidExpressionException("DIVIDE");
                    break;
                case '(':
                    if (type == "num" || type == "close" || percent) { // kasus buka stlh nilai
                        inputOp(percent,value,type,"multiply");
                        neg = false;
                    }
                    type = "open";
                    vecData.push_back(make_pair(value,type));
                    break;
                case ')':
                    if (type == "open") throw new EmptyParenthesesException(); // kasus open langsung close
                    else if (type == "close" || type == "num" || type == "percent" || type == "square") { // kasus jika tidak ada operator stlh num / close
                        percent = false;
                        vecData.push_back(make_pair(value,type));
                        value = 0;
                        type = "close";
                    } else throw new InvalidExpressionException("CLOSE PAR"); // kasus op langsung tutup
                    break;
                case '%':
                    if (type == "num" || type=="close") {
                        vecData.push_back(make_pair(value,type));
                        value = 0;
                        type = "percent";
                    }
                    else throw new InvalidExpressionException("PERCENT");
                    percent = true;
                    break;
                case '.':
                    it++;
                    while (48 <= *it && *it <= 57) {
                        dec += ((double) (*it) - 48.00) / decCount;
                        decCount *= 10;
                        it++;
                    }
                    it--;
                    if (decCount == 0.1 || *it+1 == '.') throw InvalidExpressionException("DECIMAL");
                    else {
                        type = "num";
                        value += dec;
                        dec = 0.0;
                        decCount = 10;
                    }
                    break;
                case '^': //PENGGANTI KUADRAT
                    if (type == "close" || type == "num" && !(*(it+1) >= 48 && *(it+1) <= 57)) {
                        vecData.push_back(make_pair(value,type));
                        value = 0;
                        type = "square";
                    }
                    else { 
                        throw new InvalidExpressionException("SQUARE");
                    }
                    break;
                case '~': //PENGGANTI SQRT
                    if (type == "open" || type == "plus" || type == "subtract" || type == "multiply" || type == "divide" || type == "null") { // untuk kasus setelah akar langsung angka??
                        vecData.push_back(make_pair(0,"sqrt"));
                        value = 0;
                        type = "sqrt";
                    }
                    else {
                        throw InvalidExpressionException("SQRT");
                    }
                    break;
                case 'S':
                    it+=2;
                    if (type == "open" || type == "plus" || type == "subtract" || type == "multiply" || type == "divide" || type == "null") {
                        vecData.push_back(make_pair(0,"sin"));
                    }
                    else {
                        throw InvalidExpressionException("SIN");
                    }
                    break;
                case 'C':
                    it+=2;
                    if (type == "open" || type == "plus" || type == "subtract" || type == "multiply" || type == "divide" || type == "null") {
                        vecData.push_back(make_pair(0,"cos"));
                    }
                    else {
                        throw InvalidExpressionException("COS");
                    }
                    break;
                case 'T':
                    it+=2;
                    if (type == "open" || type == "plus" || type == "subtract" || type == "multiply" || type == "divide" || type == "null") {
                        vecData.push_back(make_pair(0,"tan"));
                    }
                    else {
                        throw InvalidExpressionException("TAN");
                    }
                    break;
                // *Numbers
                case '0':
                    if (value != 0) value *= 10;
                    else if (neg) {
                        while (*it == '0') {
                            it++;
                        }
                        if (*it > 57 || *it < 48) neg = false;
                        it--;
                    } // DivideByZero dihandle di calculate
                    type = "num";
                    break;    
                default:
                    if (percent) throw new InvalidExpressionException("PERCENT");
                    else if (type == "close") throw new InvalidExpressionException("CLOSE PAR");
                    type = "num";
                    if (neg) {
                        value = unaryOperationHandler(((double) (*it) - 48), "-");
                        neg = false;
                    } else if (value < 0) {
                        value = value*10 - ((double) (*it) - 48);
                    } else { 
                        value = value*10 + ((double) (*it) - 48); 
                    }
                    break;
                
            }
        }
        if (type == "num" || type=="close" || type=="square" || type=="percent") vecData.push_back(make_pair(value,type));
        else throw new InvalidExpressionException("END");
        cout <<  "Parsed Successfully\n";
    }
}
void Parser::debugData() {
    cout.precision(15);
    for (int i=0; i<vecData.size(); i++) {
        cout << vecData[i].first << "|" << vecData[i].second << " ";
    }
}

double Parser::unaryOperationHandler(double val, string op) {
    Expression<double>* e;
    if (op == "-") {
        e = new NegativeExpression<double>(new TerminalExpression<double>(val));
    } else if (op == "percent") {
        e = new PercentExpression<double>(new TerminalExpression<double>(val));
    } else if (op == "sqrt") { // pengganti sqrt
        e = new SqrtExpression<double>(new TerminalExpression<double>(val));
    } else if (op == "square") { //pengganti kuadrat
        e = new SquareExpression<double>(new TerminalExpression<double>(val));
    } else if (op == "sin") {
        e = new SinExpression<double>(new TerminalExpression<double>(val));
    } else if (op == "cos") {
        e = new CosExpression<double>(new TerminalExpression<double>(val));
    } else if (op == "tan") {
        e = new TanExpression<double>(new TerminalExpression<double>(val));
    }
    return e->solve();
}

double Parser::binaryOperationHandler(double valfirst, double valsec, string op) {
    Expression<double>* e;
    if (op == "plus") {
        e = new AddExpression<double>(new TerminalExpression<double>(valfirst), new TerminalExpression<double>(valsec));
    } else if (op == "subtract") {
        e = new SubtractExpression<double>(new TerminalExpression<double>(valfirst), new TerminalExpression<double>(valsec));
    } else if (op == "divide") {
        e = new DivisionExpression<double>(new TerminalExpression<double>(valfirst), new TerminalExpression<double>(valsec));
    } else if (op == "multiply") {
        e = new MultiplicationExpression<double>(new TerminalExpression<double>(valfirst), new TerminalExpression<double>(valsec));
    }
    return e->solve();
}

double Parser::solve() {
    stack<double> number; //stack to store values
    stack<string> operate; //stack to store operators
    for (int i=0; i<vecData.size(); i++) {
        if (vecData[i].second == "num") {
            if (operate.size() > 0 && operate.top() == "sqrt") {
                string sqrt = operate.top();
                operate.pop();
                double res = unaryOperationHandler(vecData[i].first,sqrt);
                number.push(res);
            }
            else {
                number.push(vecData[i].first);
            }
    }
        else if (vecData[i].second == "percent" || vecData[i].second == "square") {
            double num = number.top();
            number.pop();
            double res = unaryOperationHandler(num, vecData[i].second);
            number.push(res);
        }
        else if (vecData[i].second == "open" || vecData[i].second == "sin" || vecData[i].second == "tan" || vecData[i].second == "cos" || vecData[i].second == "sqrt") {
            operate.push(vecData[i].second);
        }
        else if (vecData[i].second == "close") {
            while (!operate.empty() && (operate.top() != "open")) {
                string operater = operate.top();
                operate.pop();
                double operandtwo = number.top();
                number.pop();
                double operandone = number.top();
                number.pop();
                double result = binaryOperationHandler(operandone, operandtwo, operater);
                number.push(result);
            }
            operate.pop();
            if ((operate.size() > 0) && (operate.top() == "sqrt" || operate.top() == "sin" || operate.top() == "cos" || operate.top() == "tan")) {
                if (operate.top() == "sqrt" && number.top() < 0) {
                    throw new NegativeSqrtException();
                }
                else {
                    string operater = operate.top();
                    operate.pop();
                    double val = number.top();
                    number.pop();
                    double res = unaryOperationHandler(val, operater);
                    number.push(res);
                }
            }
        } else if ((vecData[i].second == "plus") || (vecData[i].second == "subtract")) {
            while ((operate.size() > 0) && (operate.top() != "open")) {
                string operater = operate.top();
                operate.pop();
                double operandtwo = number.top();
                number.pop();
                double operandone = number.top();
                number.pop();
                double result = binaryOperationHandler(operandone, operandtwo, operater);
                number.push(result);
            }
            operate.push(vecData[i].second);
        } else if ((vecData[i].second == "multiply") || (vecData[i].second == "divide")) {
            while ((operate.size() > 0) && (operate.top() != "plus") && (operate.top() != "subtract") && (operate.top() != "open")) {
                string operater = operate.top();
                operate.pop();
                double operandtwo = number.top();
                number.pop();
                double operandone = number.top();
                number.pop();
                if ((operandtwo == 0) && (operater=="divide")) {
                    throw new DivideByZeroException();
                }
                else {
                    double result = binaryOperationHandler(operandone, operandtwo, operater);
                    number.push(result);
                }
            }
            operate.push(vecData[i].second);
        }
    }
    while (operate.size() > 0) {
        string operater = operate.top();
        operate.pop();
        double operandtwo = number.top();
        number.pop();
        double operandone = number.top();
        number.pop();
        double result = binaryOperationHandler(operandone, operandtwo, operater);
        number.push(result);
    }
    double final = number.top();
    number.pop();
    vecData.clear();
    vecData.push_back(make_pair(final,"num"));
    return final;
}
