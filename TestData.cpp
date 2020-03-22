#include <bits/stdc++.h>
#include "Parser.hpp"
#include "Exception/OperationFailedException.hpp"
using namespace std;

int main() {
    string coba;
    cin >> coba;
    Parser test(coba);
    try {
        test.parseInput();
    } catch(BaseException* exc) {
        OperationFailedException* err = new OperationFailedException(exc);
        cout << err -> getMessage();
        return 0;
    }
        test.debugData();
    // string wkwk;
    // cin >> wkwk;
    // cout << stod(wkwk) <<endl;
    cout << endl << test.solve();
    return 0;
}