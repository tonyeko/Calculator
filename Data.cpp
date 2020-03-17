// Data.cpp
// Contributor : 13518135
/*  Implementasi Data.hpp
*/

#include "Data.hpp"
#include <iostream>
#include <vector>
using namespace std;

Data::Data(string inp) {
    input = inp;
}
Data::~Data() {}

void Data::inputOp(bool &percent, double &val, string &type, string input) {
    percent = false;
    vecData.push_back(make_pair(val,type));
    val = 0;
    type = input;
    vecData.push_back(make_pair(0,type));
}

void Data::parseInput() {
    if (input.empty()) throw NullPointerException();    
    else
    {   
        bool sin, cos, tan;
        bool neg = false;
        bool percent = false;
        double value = 0.0;
        string type = "null";
        string::iterator it;
        for (it=input.begin(); it!=input.end(); it++) {
            cout << "Type skrg: " << type << endl;
            switch(*it) {
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
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    if (percent) throw InvalidExpressionException("percent");
                    else if (type == "close") throw InvalidExpressionException("close parentheses");
                    type = "num";
                    // cout << "Value : " << value << endl;
                    if (neg) {
                        value = -1*((double) (*it) - 48);
                        neg = false;
                    } else if (value < 0) {
                        value = value*10 - ((double) (*it) - 48);
                    } else { 
                        value = value*10 + ((double) (*it) - 48); 
                    }
                    // cout << "Value New : " << value << endl;
                    break;
                // * Operators
                case '+':
                    if (type == "num") inputOp(percent,value,type,"plus");
                    else if (type == "subtract" || type=="close") type = "num";
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
                    if (type == "num") value *= 0.01;
                    else if (type == "close") {
                        inputOp(percent,value,type,"multiply");
                        value = 0.1;
                        type = "num";
                    } else throw InvalidExpressionException("percent");
                    percent = true;
                    break;
                // case '²':
                //     if (type == "num") {
                //         value *= value;
                //     } else if (type == "close") {
                //         inputOp(percent,value,type,"square");
                //     } else throw InvalidExpressionException("square");
                //     break;
                
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
    for (int i=0; i<vecData.size(); i++) {
        cout << vecData[i].first << "|" << vecData[i].second << endl;
    }
}