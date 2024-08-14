
#ifndef STACK_H
#define STACK_H

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
};



#endif //STACK_H
