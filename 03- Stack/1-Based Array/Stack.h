
#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

template <class dataType>
class Stack {
private:
    int top ;
    int length ;
    dataType * arr  ;
public:
    Stack(int size );
    ~Stack();
    void push(dataType element) ;
    void pop();
    dataType peek();
    void print() ;
    bool isEmpty();
    bool isFull();
    // ================== Added Functions ============= //
    string reverse_subwords(string str ) ;
};



#endif //STACK_H
