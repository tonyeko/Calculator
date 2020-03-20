// Data.cpp
// Contributor : 13518135, 13518030
/*  Implementasi Data.hpp
*/

#include "Data.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

Data::Data(string inp) {
    input = inp;
}

void Data::inputOp(bool &percent, bool &foundDecimal,double &val, string &type, string input) {
    percent = false;
    foundDecimal = false;
    vecData.push_back(make_pair(val,type)); // push angka
    val = 0;
    type = input;
    vecData.push_back(make_pair(0,type)); //push operator
}

void Data::parseInput() {
    if (input.empty()) throw NullPointerException();    
    else
    {   
        bool sin = false, cos = false, tan = false;
        bool foundDecimal = false;
        bool foundSqrt = false;
        bool neg = false;
        bool percent = false;
        double value = 0;
        //untuk unary 
        double num;
        bool numneg;
        string type = "null";
        string::iterator it;
        for (it=input.begin(); it!=input.end(); it++) {
            cout << "Type skrg: " << type << endl;
            switch(*it) {
                // * Operators
                case '+':
                    if (type == "num") inputOp(percent,foundDecimal,value,type,"plus");
                    else if (type == "subtract" || type == "multiply" || type=="close" || type=="open") type = "num";
                    else throw InvalidExpressionException("add");
                    break;
                case '-':
                    if (type == "subtract") throw DoubleNegationException();
                    else if (type == "num" || type=="close") inputOp(percent,foundDecimal,value,type,"subtract");
                    else {
                        type = "subtract";
                        neg = true;
                    } // throw InvalidExpressionException();
                    break;
                case '*':
                    if (type == "num" || type=="close") inputOp(percent,foundDecimal,value,type,"multiply");
                    else throw InvalidExpressionException("multiply");
                    break;
                case '/':
                    if (type == "num" || type=="close") inputOp(percent,foundDecimal,value,type,"divide");
                    else throw InvalidExpressionException("divide");
                    break;
                case '(':
                    if (type == "num" || type == "close" || percent) {
                        inputOp(percent,foundDecimal,value,type,"multiply");
                        neg = false;
                    }
                    type = "open";
                    vecData.push_back(make_pair(value,type));
                    break;
                case ')':
                    if (type == "open") throw EmptyParenthesesException();
                    else if (type == "close" || type == "num") {
                        percent = false;
                        vecData.push_back(make_pair(value,type));
                        value = 0;
                        type = "close";
                    } else throw InvalidExpressionException("close parentheses");
                    break;
                case '%':
                    if (type == "num") value = unaryOperationHandler(value, "%");
                    else if (type == "close") {
                        inputOp(percent,foundDecimal,value,type,"multiply");
                        value = 0.01;
                        type = "num";
                    } else throw InvalidExpressionException("percent");
                    percent = true;
                    break;
                case '.':
                    if (foundDecimal) throw InvalidExpressionException("decimal");
                    else {
                        foundDecimal = true;
                        if (type == "num") {
                            inputOp(percent,foundDecimal,value,type,"decimal");
                        } else throw InvalidExpressionException("decimal");
                        break;
                    }
                case '^': //PENGGANTI KUADRAT
                    if (type == "num") value = unaryOperationHandler(value, "^");
                    else throw InvalidExpressionException("square");
                    break;
                case '~': //PENGGANTI SQRT
                    it++;
                    if (value != 0) { // untuk kasus setelah angka langsung akar
                            inputOp(percent,foundDecimal,value,type,"multiply");
                            value = 0;
                            type = "num";
                    }
                    if (*it == '(') {
                        it++;
                        num = 0;
                        while (*it != ')' && it != input.end()) {
                            // cout << ((double) (*it) - 48) << "AAAA" << endl;
                            if (*it == '-') {
                                throw NegativeSqrtException();
                            }
                            num = num*10 + ((double) (*it) - 48); 
                            it++;
                        }
                        if (it == input.end()) {
                            throw InvalidExpressionException("close par");
                        } else {
                            value = unaryOperationHandler(num, "~");
                            type = "num";
                        }
                    } else {
                        if (*it > 57 || *it < 48) {
                            throw InvalidExpressionException("sqrt");
                        } else {
                            value = unaryOperationHandler(((double) (*it) - 48), "~");
                            type = "num";
                        }
                    }
                    break;
                case 'S':
                    it+=4;
                    num = 0; numneg = false;
                    while (*it != ')' && it != input.end()) {
                        if (*it == '-') {
                            numneg = true;
                            *it++;
                        }
                        if (numneg) {
                            value = value*10 - ((double) (*it) - 48);
                        } else {
                            num = num*10 + ((double) (*it) - 48); 
                        }
                        it++;
                    }
                    if (it == input.end()) {
                        throw InvalidExpressionException("close par");
                    } else {
                        value = unaryOperationHandler(num, "S");
                        type = "num";
                    }
                    break;
                case 'C':
                    it+=4;
                    num = 0; numneg = false;
                    while (*it != ')' && it != input.end()) {
                        if (*it == '-') {
                            numneg = true;
                            *it++;
                        }
                        if (numneg) {
                            value = value*10 - ((double) (*it) - 48);
                        } else {
                            num = num*10 + ((double) (*it) - 48); 
                        }
                        it++;
                    }
                    if (it == input.end()) {
                        throw InvalidExpressionException("close par");
                    } else {
                        value = unaryOperationHandler(num, "C");
                        type = "num";
                    }
                    break;
                case 'T':
                    it+=4;
                    num = 0; numneg = false;
                    while (*it != ')' && it != input.end()) {
                        if (*it == '-') {
                            numneg = true;
                            *it++;
                        }
                        if (numneg) {
                            value = value*10 - ((double) (*it) - 48);
                        } else {
                            num = num*10 + ((double) (*it) - 48); 
                        }
                        it++;
                    }
                    if (it == input.end()) {
                        throw InvalidExpressionException("close par");
                    } else {
                        value = unaryOperationHandler(num, "T");
                        type = "num";
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
                    if (percent) throw InvalidExpressionException("percent");
                    else if (type == "close") throw InvalidExpressionException("close parentheses");
                    type = "num";
                    // cout << "Value : " << value << endl;
                    if (neg) {
                        value = unaryOperationHandler(((double) (*it) - 48), "-");
                        neg = false;
                    } else if (value < 0) {
                        value = value*10 - ((double) (*it) - 48);
                    } else { 
                        value = value*10 + ((double) (*it) - 48); 
                    }
                    // cout << "Value New : " << value << endl;
                    break;
                
            }
            cout << *it << endl;
        }
        if (type == "num" || type=="close") vecData.push_back(make_pair(value,type));
        // else if (type == "close") {}
        else throw InvalidExpressionException("end");
        cout <<  "Parsed Successfully\n";
    }
}
void Data::debugData() {
    cout.precision(15);
    for (int i=0; i<vecData.size(); i++) {
        cout << vecData[i].first << "|" << vecData[i].second << " ";
    }
}

double Data::unaryOperationHandler(double val, string op) {
    Expression<double>* e;
    if (op == "-") {
        e = new NegativeExpression<double>(new TerminalExpression<double>(val));
    } else if (op == "%") {
        e = new PercentExpression<double>(new TerminalExpression<double>(val));
    } else if (op == "~") { // pengganti sqrt
        e = new SqrtExpression<double>(new TerminalExpression<double>(val));
    } else if (op == "^") { //pengganti kuadrat
        e = new SquareExpression<double>(new TerminalExpression<double>(val));
    } else if (op == "S") {
        e = new SinExpression<double>(new TerminalExpression<double>(val));
    } else if (op == "C") {
        e = new CosExpression<double>(new TerminalExpression<double>(val));
    } else if (op == "T") {
        e = new TanExpression<double>(new TerminalExpression<double>(val));
    }
    return e->solve();
}

double Data::binaryOperationHandler(double valfirst, double valsec, string op) {
    Expression<double>* e;
    int length = to_string(int(valsec)).length();
    if (op == "plus") {
        e = new AddExpression<double>(new TerminalExpression<double>(valfirst), new TerminalExpression<double>(valsec));
    } else if (op == "subtract") {
        e = new SubtractExpression<double>(new TerminalExpression<double>(valfirst), new TerminalExpression<double>(valsec));
    } else if (op == "decimal") {
        e = new DecimalExpression<double>(new TerminalExpression<double>(valfirst), new TerminalExpression<double>(valsec), length);
    } else if (op == "divide") {
        e = new DivisionExpression<double>(new TerminalExpression<double>(valfirst), new TerminalExpression<double>(valsec));
    } else if (op == "multiply") {
        e = new MultiplicationExpression<double>(new TerminalExpression<double>(valfirst), new TerminalExpression<double>(valsec));
    }
    return e->solve();
}

void Data::solve() {
    stack<double> number; //stack to store values
    stack<string> operate; //stack to store operators
    for (int i=0; i<vecData.size(); i++) {
        if (vecData[i].second == "num") {
            number.push(vecData[i].first);
        }
        else if (vecData[i].second == "open") {
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
        }
        else if ((vecData[i].second == "multiply") || (vecData[i].second == "divide")) {
            while ((operate.size() > 0) && (operate.top() != "plus") && (operate.top() != "subtract") && (operate.top() != "open")) {
                string operater = operate.top();
                operate.pop();
                double operandtwo = number.top();
                number.pop();
                double operandone = number.top();
                number.pop();
                if ((operandtwo == 0) && (operater=="divide")) {
                    throw DivideByZeroException();
                }
                else {
                    double result = binaryOperationHandler(operandone, operandtwo, operater);
                    number.push(result);
                }
            }
            operate.push(vecData[i].second);
        }
        else if (vecData[i].second == "decimal") {
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
}