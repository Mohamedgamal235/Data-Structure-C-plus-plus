
#include "Stack.h"
#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
using namespace std;

template<class dataType>
Stack<dataType>::Stack() {}

/////////////////////////////////////////

template<class dataType>
Stack<dataType>::~Stack() {
    list.clear() ;
}

/////////////////////////////////////////

template<class dataType>
bool Stack<dataType> :: isEmpty() {
    return list.isEmpty() ;
}

/////////////////////////////////////////

template<class dataType>
void Stack<dataType> :: push(dataType element) {
    list.insertAtHead(element) ;
}

/////////////////////////////////////////

template<class dataType>
void Stack<dataType>::pop() {
    assert(!isEmpty()) ;
    list.removeHead();
}

/////////////////////////////////////////

template<class dataType>
dataType Stack<dataType>::peek() {
    assert(!isEmpty()) ;
    return list.front();
}

/////////////////////////////////////////

template<class dataType>
void Stack<dataType>::print() {
    list.print();
}

/////////////////////////////////////////

template<class dataType>
int Stack<dataType> :: precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (c == '^')
        return 3;
    return 0;
}

template<class dataType>
string Stack<dataType> :: infixToPostfix(string input) {
    string postfix = "" ;
    Stack<char> operators ;

    for (auto c : input) {
        if (isdigit(c) || isalpha(c))
            postfix += c ;
        else if (c == '(')
            operators.push(c) ;
        else if (c == ')') {
            while (!operators.isEmpty() && operators.peek() != '(' ) {
                postfix += operators.peek() ;
                operators.pop() ;
            }
            operators.pop() ; // remove -> (
        }
        else {
            while (!operators.isEmpty() && precedence(c) <= precedence(operators.peek())) {
                postfix += operators.peek() ;
                operators.pop() ;
            }
            operators.push(c);
        }
    }

    while (!operators.isEmpty()) {
        postfix += operators.peek() ;
        operators.pop() ;
    }

    return postfix ;
}

/////////////////////////////////////////

template<class dataType>
double Stack<dataType> :: result(double x , double y , char c ) {
    if (c == '+')
        return x + y ;
    if (c == '*')
        return x * y ;
    if (c == '-')
        return x - y ;
    if (c == '/')
        return x / y ;

    return pow(x,y) ; // for ^
}

template<class dataType>
double Stack<dataType> :: postfixEvaluation(string postfix) {
    Stack<double> evaluation ;
    for (auto c : postfix) {
        if (isdigit(c))
            evaluation.push(c-'0') ;
        else {
            double x = evaluation.peek() ;
            evaluation.pop() ;

            double y = evaluation.peek() ;
            evaluation.pop() ;
            // y , x not x , y Bcz divid and power
            double val = result(y , x , c ) ;
            evaluation.push(val) ;
        }
    }

    return evaluation.peek();
}

/////////////////////////////////////////

template<class dataType>
string Stack<dataType> :: infixToPrefix(string input) {

}