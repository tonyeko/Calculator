// Data.cpp
// Contributor : 13518135, 13518030
/*  Implementasi Data.hpp
*/

#include "Data.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

Data::Data(string inp) {
    input = inp;
    string::iterator it;
    cout << "INPUT: " << input << endl;
}

void Data::inputOp(bool &percent, double &val, string &type, string input) {
    percent = false;
    vecData.push_back(make_pair(val,type)); // push angka
    val = 0;
    type = input;
    vecData.push_back(make_pair(0,type)); //push operator
}

void Data::parseInput() {
    if (input.empty()) throw NullPointerException();    
    else {   
        bool sin = false, cos = false, tan = false;
        bool foundSqrt = false;
        bool neg = false;
        bool percent = false;
        double value = 0;
        double dec = 0.0;
        double decCount = 10;
        //untuk unary 
        double num;
        bool numneg;
        string type = "null";
        string::iterator it;
        for (it=input.begin(); it!=input.end(); it++) {
            cout << "Type skrg: " << type << endl;
            switch(*it) {
                // * Operators
                case '+':
                    if (type == "num") inputOp(percent,value,type,"plus");
                    else if (type == "subtract" || type == "multiply" || type=="close" || type=="open") type = "num";
                    else throw new InvalidExpressionException("ADD");
                    break;
                case '-':
                    if (type == "subtract") throw new DoubleNegationException();
                    else if (type == "num" || type=="close") inputOp(percent,value,type,"subtract");
                    else {
                        type = "subtract";
                        neg = true;
                    } // throw InvalidExpressionException();
                    break;
                case 'x':
                    if (type == "num" || type=="close") inputOp(percent,value,type,"multiply");
                    else throw new InvalidExpressionException("MULTIPLY");
                    break;
                case '/': // divide by 0 dihandle solve
                    if (type == "num" || type=="close") inputOp(percent,value,type,"divide");
                    else throw new InvalidExpressionException("DIVIDE");
                    break;
                case '(':
                    if (type == "num" || type == "close" || percent) { // kasus buka stlh nilai
                        inputOp(percent,value,type,"multiply");
                        neg = true;
                    }
                    type = "open";
                    vecData.push_back(make_pair(value,type));
                    break;
                case ')':
                    if (type == "open") throw new EmptyParenthesesException(); // kasus open langsung close
                    else if (type == "close" || type == "num") { // kasus jika tidak ada operator stlh num / close
                        percent = false;
                        vecData.push_back(make_pair(value,type));
                        value = 0;
                        type = "close";
                    } else throw new InvalidExpressionException("CLOSE PAR"); // kasus op langsung tutup
                    break;
                case '%':
                    if (type == "num") value = unaryOperationHandler(value, "%");
                    else if (type == "close") { // Kasus persen langsung stlh akar
                        inputOp(percent,value,type,"multiply");
                        value = 0.01;
                        type = "num";
                    } else throw new InvalidExpressionException("PERCENT");
                    percent = true;
                    break;
                case '.':
                    it++;
                    while (48 <= *it && *it <= 57) {
                        dec += ((double) (*it) - 48.00) / decCount;
                        decCount *= 10;
                        it++;
                    }
                    it--;
                    if (decCount == 0.1 || *it+1 == '.') throw InvalidExpressionException("DECIMAL");
                    else {
                        type = "num";
                        value += dec;
                        dec = 0.0;
                        decCount = 10;
                    }
                    break;
                case '^': //PENGGANTI KUADRAT
                    if (type == "num") {
                        value = unaryOperationHandler(value, "^");
                        if (*(it+1) >= 48 && *(it+1) <= 57) { 
                            throw new InvalidExpressionException("SQUARE");
                        }
                    }
                    else throw new InvalidExpressionException("SQUARE");
                    break;
                case '~': //PENGGANTI SQRT
                    it++;
                    if (value != 0) { // untuk kasus setelah angka langsung akar
                        inputOp(percent,value,type,"multiply");
                        value = 0;
                        type = "num";
                    }
                    if (*it == '(') {
                        it++;
                        num = 0;
                        while (*it != ')' && it != input.end()) {
                            // cout << ((double) (*it) - 48) << "AAAA" << endl;
                            if (*it == '-') {
                                throw new NegativeSqrtException();
                            }
                            num = num*10 + ((double) (*it) - 48);
                            it++;
                        }
                        if (it == input.end()) {
                            throw new InvalidExpressionException("CLOSE PAR");
                        } else {
                            value = unaryOperationHandler(num, "~");
                            type = "num";
                        }
                    } else {
                        if (*it > 57 || *it < 48) { // setelah SQRT bukan angka
                            throw new InvalidExpressionException("SQRT");
                        } else {
                            while (*it >= 48 &&  *it <= 57 && it != input.end()) {
                                cout << ((double) (*it) - 48) << "AAAA" << endl;
                                if (*it == '-') {
                                    throw new NegativeSqrtException();
                                }
                                num = num*10 + ((double) (*it) - 48);
                                it++;
                                // cout << num << endl;
                            } 
                            it--;
                            value = unaryOperationHandler(num, "~");
                            type = "num";
                        }
                    }
                    break;
                case 'S':
                    it+=4;
                    num = 0; numneg = false;
                    if (*it < 48 || *it > 57) {
                        throw new InvalidExpressionException("SIN");
                    }
                    while (*it != ')' && it != input.end()) {
                        if (*it == '-') {
                            numneg = true;
                            *it++;
                        }
                        if (numneg) {
                            value = value*10 - ((double) (*it) - 48);
                        } else {
                            num = num*10 + ((double) (*it) - 48); 
                        }
                        it++;
                    }
                    if (it == input.end()) {
                        throw new InvalidExpressionException("CLOSE PAR");
                    } else {
                        if (*(it+1) > 57 || *(it+1) < 48) { 
                            value = unaryOperationHandler(num, "SIN");
                            type = "num";
                        } else { //setelah sin langsung angka, contoh: SIN(2)2
                            throw new InvalidExpressionException("SIN");
                        }
                    }
                    break;
                case 'C':
                    it+=4;
                    if (*it > 57 || *it < 48) {
                        throw new InvalidExpressionException("COS");
                    }
                    num = 0; numneg = false;
                    while (*it != ')' && it != input.end()) {
                        if (*it == '-') {
                            numneg = true;
                            *it++;
                        }
                        if (numneg) {
                            value = value*10 - ((double) (*it) - 48);
                        } else {
                            num = num*10 + ((double) (*it) - 48); 
                        }
                        it++;
                    }
                    if (it == input.end()) {
                        throw new InvalidExpressionException("CLOSE PAR");
                    } else {
                        if (*(it+1) > 57 || *(it+1) < 48) { 
                            value = unaryOperationHandler(num, "COS");
                            type = "num";
                        } else { //setelah sin langsung angka, contoh: COS(2)2
                            throw new InvalidExpressionException("COS");
                        }
                    }
                    break;
                case 'T':
                    it+=4;
                    if (*it > 57 || *it < 48) {
                        throw new InvalidExpressionException("TAN");
                    }
                    num = 0; numneg = false;
                    while (*it != ')' && it != input.end()) {
                        if (*it == '-') {
                            numneg = true;
                            *it++;
                        }
                        if (numneg) {
                            value = value*10 - ((double) (*it) - 48);
                        } else {
                            num = num*10 + ((double) (*it) - 48); 
                        }
                        it++;
                    }
                    if (it == input.end()) {
                        throw new InvalidExpressionException("CLOSE PAR");
                    } else {
                        if (*(it+1) < 48 || *(it+1) > 57) { 
                            value = unaryOperationHandler(num, "TAN");
                            type = "num";
                        } else { //setelah sin langsung angka, contoh: TAN(2)2
                            throw new InvalidExpressionException("TAN");
                        }
                    }
                    break;
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
                default:
                    if (percent) throw new InvalidExpressionException("PERCENT");
                    else if (type == "close") throw new InvalidExpressionException("CLOSE PAR");
                    type = "num";
                    // cout << "Value : " << value << endl;
                    if (neg) {
                        value = unaryOperationHandler(((double) (*it) - 48), "-");
                        neg = false;
                    } else if (value < 0) {
                        value = value*10 - ((double) (*it) - 48);
                    } else { 
                        value = value*10 + ((double) (*it) - 48); 
                    }
                    // cout << "Value New : " << value << endl;
                    break;
                
            }
            cout << *it << endl;
        }
        if (type == "num" || type=="close") vecData.push_back(make_pair(value,type));
        // else if (type == "close") {}
        else throw new InvalidExpressionException("END");
        cout <<  "Parsed Successfully\n";
    }
}
void Data::debugData() {
    cout.precision(15);
    for (int i=0; i<vecData.size(); i++) {
        cout << vecData[i].first << "|" << vecData[i].second << " ";
    }
}

double Data::unaryOperationHandler(double val, string op) {
    Expression<double>* e;
    if (op == "-") {
        e = new NegativeExpression<double>(new TerminalExpression<double>(val));
    } else if (op == "%") {
        e = new PercentExpression<double>(new TerminalExpression<double>(val));
    } else if (op == "~") { // pengganti sqrt
        e = new SqrtExpression<double>(new TerminalExpression<double>(val));
    } else if (op == "^") { //pengganti kuadrat
        e = new SquareExpression<double>(new TerminalExpression<double>(val));
    } else if (op == "SIN") {
        e = new SinExpression<double>(new TerminalExpression<double>(val));
    } else if (op == "COS") {
        e = new CosExpression<double>(new TerminalExpression<double>(val));
    } else if (op == "TAN") {
        e = new TanExpression<double>(new TerminalExpression<double>(val));
    }
    return e->solve();
}

double Data::binaryOperationHandler(double valfirst, double valsec, string op) {
    Expression<double>* e;
    int length = to_string(int(valsec)).length();
    if (op == "plus") {
        e = new AddExpression<double>(new TerminalExpression<double>(valfirst), new TerminalExpression<double>(valsec));
    } else if (op == "subtract") {
        e = new SubtractExpression<double>(new TerminalExpression<double>(valfirst), new TerminalExpression<double>(valsec));
    } else if (op == "decimal") {
        e = new DecimalExpression<double>(new TerminalExpression<double>(valfirst), new TerminalExpression<double>(valsec), length);
    } else if (op == "divide") {
        e = new DivisionExpression<double>(new TerminalExpression<double>(valfirst), new TerminalExpression<double>(valsec));
    } else if (op == "multiply") {
        e = new MultiplicationExpression<double>(new TerminalExpression<double>(valfirst), new TerminalExpression<double>(valsec));
    }
    return e->solve();
}

double Data::solve() {
    stack<double> number; //stack to store values
    stack<string> operate; //stack to store operators
    for (int i=0; i<vecData.size(); i++) {
        if (vecData[i].second == "num") {
            number.push(vecData[i].first);
        }
        else if (vecData[i].second == "open") {
            operate.push(vecData[i].second);
        }
        else if (vecData[i].second == "close") {
            while (!operate.empty() && (operate.top() != "open")) {
                string operater = operate.top();
                operate.pop();
                double operandtwo = number.top();
                number.pop();
                double operandone = number.top();
                number.pop();
                double result = binaryOperationHandler(operandone, operandtwo, operater);
                number.push(result);
            }
                operate.pop();
        } else if ((vecData[i].second == "plus") || (vecData[i].second == "subtract")) {
            while ((operate.size() > 0) && (operate.top() != "open")) {
                string operater = operate.top();
                operate.pop();
                double operandtwo = number.top();
                number.pop();
                double operandone = number.top();
                number.pop();
                double result = binaryOperationHandler(operandone, operandtwo, operater);
                number.push(result);
            }
            operate.push(vecData[i].second);
        }
        else if ((vecData[i].second == "multiply") || (vecData[i].second == "divide")) {
            while ((operate.size() > 0) && (operate.top() != "plus") && (operate.top() != "subtract") && (operate.top() != "open")) {
                string operater = operate.top();
                operate.pop();
                double operandtwo = number.top();
                number.pop();
                double operandone = number.top();
                number.pop();
                if ((operandtwo == 0) && (operater=="divide")) {
                    throw new DivideByZeroException();
                }
                else {
                    double result = binaryOperationHandler(operandone, operandtwo, operater);
                    number.push(result);
                }
            }
            operate.push(vecData[i].second);
        }
        else if (vecData[i].second == "decimal") {
            operate.push(vecData[i].second);
        }
    }
    while (operate.size() > 0) {
        string operater = operate.top();
        operate.pop();
        double operandtwo = number.top();
        number.pop();
        double operandone = number.top();
        number.pop();
        double result = binaryOperationHandler(operandone, operandtwo, operater);
        number.push(result);
    }
    double final = number.top();
    number.pop();
    vecData.clear();
    vecData.push_back(make_pair(final,"num"));
    return final;
}