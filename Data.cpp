// Data.cpp
// Contributor : 13518135, 13518030
/*  Implementasi Data.hpp
*/

#include "Data.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

Data::Data(string inp) {
    input = inp;
}

void Data::inputOp(bool &percent, double &val, string &type, string input) {
    number.push(val);



    percent = false;
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
                    if (type == "num") inputOp(percent,value,type,"plus");
                    else if (type == "subtract" || type == "multiply" || type=="close") type = "num";
                    else throw InvalidExpressionException("add");
                    break;
                case '-':
                    if (type == "subtract") throw DoubleNegationException();
                    else if (type == "num" || type=="close") inputOp(percent,value,type,"subtract");
                    else {
                        type = "subtract";
                        neg = true;
                    } // throw InvalidExpressionException();
                    break;
                case '*':
                    if (type == "num" || type=="close") inputOp(percent,value,type,"multiply");
                    else throw InvalidExpressionException("multiply");
                    break;
                case '/':
                    if (type == "num" || type=="close") inputOp(percent,value,type,"divide");
                    else throw InvalidExpressionException("divide");
                    break;
                case '(':
                    if (type == "num" || type == "close" || percent) {
                        inputOp(percent,value,type,"multiply");
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
                        inputOp(percent,value,type,"multiply");
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
                            inputOp(percent,value,type,"decimal");
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
                            inputOp(percent,value,type,"multiply");
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
        if (type == "num") vecData.push_back(make_pair(value,type));
        else if (type == "close") {}
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

void Data::solve() {
    
}