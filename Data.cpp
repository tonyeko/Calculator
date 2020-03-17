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

void Data::inputOp(double& val, string& type, string input) {
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
                    if (type == "num") inputOp(value,type,"plus");
                    else if (type == "subtract") type = "num";
                    else throw InvalidOperatorException();
                    break;
                case '-':
                    if (type == "subtract") throw DoubleNegationException();
                    else if (type == "num") inputOp(value,type,"subtract");
                    else {
                        type = "subtract";
                        neg = true;
                    } // throw InvalidOperatorException();
                    break;
                case '*':
                    if (type == "num") inputOp(value,type,"multiply");
                    else throw InvalidOperatorException();
                    break;
                case '/':
                    if (type == "num") inputOp(value,type,"divide");
                    else throw InvalidOperatorException();
                    break;

            }
            cout << *it << endl;
        }
        vecData.push_back(make_pair(value,type));
        cout <<  "Parsed Successfully\n";
    }
}

void Data::debugData() {
    for (int i=0; i<vecData.size(); i++) {
        cout << vecData[i].first << "|" << vecData[i].second << endl;
    }
}