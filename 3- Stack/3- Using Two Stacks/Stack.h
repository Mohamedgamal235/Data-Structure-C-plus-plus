
#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

//==================================//
// USE ONLY ONE ARRAY NOT TWO ARRAY //
//==================================//

template <class dataType>
class Stack {
private:
    int top1 ;
    int top2 ;
    int length ;
    dataType * arr  ;
public:
    Stack(int size );
    ~Stack();
    void push(int id  , dataType element) ;
    void pop(int id );
    dataType peek(int id );
    void print() ;
    bool isEmpty();
    bool isFull();
};


#endif //STACK_H
