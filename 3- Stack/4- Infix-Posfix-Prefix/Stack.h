
#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <vector>
#include "SinglyLinkedList.cpp"
using namespace std;

template <class dataType>
class Stack {
private:
    SinglyLinkedList<dataType> list ;
public:
    Stack();
    ~Stack();
    void push(dataType element) ;
    void pop();
    dataType peek();
    void print() ;
    bool isEmpty();
    ///////////////////////////////////
    int precedence(char c ) ;
    string infixToPostfix(string input) ;
    double postfixEvaluation(string posfix) ;
    double result(double x , double y , char c ) ;
    string infixToPrefix(string input) ;
};

#endif //STACK_H
