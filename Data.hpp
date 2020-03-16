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
#include "Exception/InvalidOperatorException.hpp"
#include "Exception/DoubleNegationException.hpp"
using namespace std;

class Data {
protected: 
    // First: value, Second:type
    vector<pair<double,string>> vecData; //isi:token
    string input; // to parse
public:
    Data(string inp);
    ~Data();
    void parseInput();
    void debugData();
};


#endif // Data.hpp