#include <bits/stdc++.h>
#include "Data.hpp"
using namespace std;

int main() {
    string coba;
    cin >> coba;
    Data test(coba);
    test.parseInput();
    test.debugData();
    cout << test.solve();
}