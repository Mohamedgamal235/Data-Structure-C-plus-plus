#include "Queue.h"
#include <cassert>
#include <iostream>
using namespace std;

template<class dataType>
Queue<dataType>::Queue(int length) : st1(length), st2(length) {
    this->length = length;
    added_elements = 0;
}

///////////////////////////////////////

template<class dataType>
Queue<dataType>::~Queue() {}

///////////////////////////////////////

template<class dataType>
bool Queue<dataType>::isFull() {
    return added_elements == length;
}

///////////////////////////////////////

template<class dataType>
bool Queue<dataType>::isEmpty() {
    return added_elements == 0;
}

///////////////////////////////////////

template<class dataType>
void Queue<dataType>::enqueue(dataType element) {
    assert(!isFull());
    reverseStacks(st1, st2);
    st2.push(element);
    reverseStacks(st2, st1);
    added_elements++;
}

///////////////////////////////////////

template<class dataType>
void Queue<dataType>::reverseStacks(Stack<dataType>& st1, Stack<dataType>& st2) {
    while (!st1.isEmpty()) {
        st2.push(st1.peek());
        st1.pop();
    }
}

///////////////////////////////////////

template<class dataType>
dataType Queue<dataType>::dequeue() {
    assert(!isEmpty());
    dataType val = st1.peek();
    st1.pop();
    added_elements--;
    return val;
}

///////////////////////////////////////

template<class dataType>
void Queue<dataType>::print() {
    assert(!isEmpty());
    st1.print();
}

///////////////////////////////////////

template<class dataType>
dataType Queue<dataType>::first_element() {
    assert(!isEmpty());
    return st1.peek();
}

///////////////////////////////////////

template<class dataType>
int Queue<dataType>::size() {
    return added_elements;
}
