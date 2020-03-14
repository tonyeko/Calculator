#include "TerminalExpression.hpp"
#include "NegativeExpression.hpp"
#include "SubstractExpression.hpp"
#include <iostream>
using namespace std;

int main() {
    Expression* e1 = new NegativeExpression(new TerminalExpression(5));
    Expression* e2 = new SubstractExpression(new TerminalExpression(5.99123), new TerminalExpression(6.91283));
    cout << e1->solve() << endl;
    cout << e2->solve() << endl;

    return 0;
}