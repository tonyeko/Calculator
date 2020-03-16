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

            switch(*it) {
                // Numbers
                case '0':
                    type = "num";
                    if (value != 0) {
                        value *= 10;
                    } else if (neg) {
                        while (*it == '0') {
                            it++;
                        }
                        if (*it > 57 || *it < 48) neg = false;
                        it--;
                    }
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
                // Operators
                case '+':
                    if (type == "num") {
                        vecData.push_back(make_pair(value,type));
                        value = 0;
                        vecData.push_back(make_pair(0,"plus"));
                    } else {
                        throw InvalidOperatorException();
                    }
                    break;
                case '-':
                    if (neg && value != 0) {
                        throw DoubleNegationException();
                    } if (type == "num") {
                        vecData.push_back(make_pair(value,type));
                        value = 0;
                        vecData.push_back(make_pair(0,"subtract"));
                    } else {
                        type = "num";
                        neg = true;
                    }
                        // throw InvalidOperatorException();
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