
#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <vector>
#include "Queue.cpp"
using namespace std;

template <class dataType>
class Stack {
private:
    Queue<dataType> q ;
    int added_elements {} ;
public:
    Stack(int size) ;
    ~Stack();
    void push(dataType element) ;
    void pop();
    dataType peek();
    void print() ;
    bool isEmpty();
};

#endif //STACK_H
