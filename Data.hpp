// Data.hpp
// Contributor : 13518135
/*  Includes string parser
    Stores temp data
*/

#ifndef DATA_HPP
#define DATA_HPP
#include <iostream>
#include <vector>
using namespace std;

class Data {
protected: 
    // First: value, Second:type
    vector<pair<double,string>> vecData; //isi:token;
    string input; // to parse
public:
    Data(string inp) {
        input = inp;
    }

    ~Data() {}

    void parseInput() {
        if (input.empty()) {
            // THROW NULL POINTER EXCEPTION
        } else {
            cout <<  "Parses\n";//Parse
        }
    }    


};


#endif // Data.hpp