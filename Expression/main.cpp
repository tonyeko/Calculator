#include "TerminalExpression.hpp"
#include "SquareExpression.hpp"
#include "AddExpression.hpp"
#include "SubstractExpression.hpp"
#include "PercentExpression.hpp"
#include "SinExpression.hpp"
#include "CosExpression.hpp"
#include "TanExpression.hpp"
#include <iostream>
using namespace std;

int main() {
    Expression* e1 = new SquareExpression(new TerminalExpression(5));
    Expression* e2 = new AddExpression(new TerminalExpression(5.99123), new TerminalExpression(6.91283));
    Expression* e3 = new SubstractExpression(new TerminalExpression(5.99123), new TerminalExpression(6.91283));
    Expression* e4 = new PercentExpression(new TerminalExpression(5));
    Expression* e5 = new SinExpression(new TerminalExpression(2.45));
    Expression* e6 = new CosExpression(new TerminalExpression(2.45));
    Expression* e7 = new TanExpression(new TerminalExpression(2.45));
    cout << e1->solve() << endl;
    cout << e2->solve() << endl;
    cout << e3->solve() << endl;
    cout << e4->solve() << endl;
    cout << e5->solve() << endl;
    cout << e6->solve() << endl;
    cout << e7->solve() << endl;

    delete e1;
    delete e2;
    delete e3;
    delete e4;
    delete e5;
    delete e6;
    delete e7;
    return 0;
}