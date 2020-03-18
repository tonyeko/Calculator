#include "TerminalExpression.hpp"
#include "SquareExpression.hpp"
#include "AddExpression.hpp"
#include "SubtractExpression.hpp"
#include "PercentExpression.hpp"
#include "SinExpression.hpp"
#include "CosExpression.hpp"
#include "TanExpression.hpp"
#include "DecimalExpression.hpp"
#include "Memory.hpp"
#include <iostream>
using namespace std;

int main() {
    Expression<double>* e1 = new SquareExpression<double>(new TerminalExpression<double>(5));
    e1 = new SinExpression<double>(new TerminalExpression<double>(5));
    Expression<double>* e2 = new AddExpression<double>(new TerminalExpression<double>(5.99123), new TerminalExpression<double>(6.0));
    Expression<double>* e3 = new SubtractExpression<double>(new TerminalExpression<double>(5.99123), new TerminalExpression<double>(6.91283));
    Expression<double>* e4 = new PercentExpression<double>(new TerminalExpression<double>(5));
    Expression<double>* e5 = new SinExpression<double>(new TerminalExpression<double>(2.45));
    Expression<double>* e6 = new CosExpression<double>(new TerminalExpression<double>(2.45));
    Expression<double>* e7 = new TanExpression<double>(new TerminalExpression<double>(2.45));
    Expression<double>* e8 = new DecimalExpression<double, 5>(new TerminalExpression<double>(12345));
    Memory<double> m;
    m.MC(e1); m.MC(e2); m.MC(e3); m.MC(e4); m.MC(e5); m.MC(e6);
    m.clear();
    m.MC(new TerminalExpression<double>(1004));
    Expression<double>* test = m.MR(); 
    cout << test->solve() << endl;
    cout << e1->solve() << endl;
    cout << e2->solve() << endl;
    cout << e3->solve() << endl;
    cout << e4->solve() << endl;
    cout << e5->solve() << endl;
    cout << e6->solve() << endl;
    cout << e7->solve() << endl;
    cout << e8->solve() << endl;

    delete e1;
    delete e2;
    delete e3;
    delete e4;
    delete e5;
    delete e6;
    delete e7;
    delete e8;
    return 0;
}