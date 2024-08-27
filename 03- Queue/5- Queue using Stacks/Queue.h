
#ifndef QUEUE_H
#define QUEUE_H
#include "Stack.cpp"

template<class dataType>
class Queue {
private:
    int length ;
    int added_elements ;
    Stack<dataType> st1 ;
    Stack<dataType> st2 ;
public:
    Queue(int length ) ;
    ~Queue() ;
    void enqueue(dataType val) ;
    void reverseStacks(Stack<dataType> & st1 , Stack<dataType> & st2) ;
    dataType dequeue() ;
    void print();
    bool isEmpty();
    bool isFull() ;
    dataType first_element() ;
    int size() ;
};


#endif //QUEUE_H
