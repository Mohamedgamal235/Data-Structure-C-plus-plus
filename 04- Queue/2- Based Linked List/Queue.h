#ifndef QUEUE_H
#define QUEUE_H
#include "SinglyLinkedList.cpp"

template<class dataType>
class Queue {
private:
    SinglyLinkedList<dataType> list;
public:
    Queue();
    ~Queue();
    void enqueue(dataType val);
    dataType dequeue();
    void print();
    void clear();
    bool isEmpty();
    dataType first_element();
    dataType last_element();
    int size();
};

#endif //QUEUE_H
