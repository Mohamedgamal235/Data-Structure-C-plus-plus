
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

};



#endif //STACK_H
