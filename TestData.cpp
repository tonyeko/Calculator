#include <bits/stdc++.h>
#include "Data.hpp"
#include "Exception/OperationFailedException.hpp"
using namespace std;

int main() {
    string coba;
    cin >> coba;
    Data test(coba);
    try {
        test.parseInput();
        test.debugData();
    } catch(BaseException* exc) {
        OperationFailedException* err = new OperationFailedException(exc);
        cout << err -> getMessage();
        return 0;
    }
    
    cout << endl << test.solve();
    return 0;
}