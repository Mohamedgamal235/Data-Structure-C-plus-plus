#include "Queue.h"
#include <cassert>
#include <iostream>
using namespace std;

template<class dataType>
Queue<dataType>::Queue() {}

///////////////////////////////////////

template<class dataType>
Queue<dataType>::~Queue() {
    clear();
}

///////////////////////////////////////

template<class dataType>
bool Queue<dataType>::isEmpty() {
    return list.isEmpty();
}

///////////////////////////////////////

template<class dataType>
void Queue<dataType>::enqueue(dataType element) {
    list.insertAtTail(element);
}

///////////////////////////////////////

template<class dataType>
dataType Queue<dataType>::dequeue() {
    assert(!isEmpty());
    dataType frontElement = list.front();
    list.removeHead();
    return frontElement;
}

///////////////////////////////////////

template<class dataType>
void Queue<dataType>::clear() {
    list.clear();
}

///////////////////////////////////////

template<class dataType>
void Queue<dataType>::print() {
    list.print();
}

///////////////////////////////////////

template<class dataType>
dataType Queue<dataType>::first_element() {
    return list.front();
}

///////////////////////////////////////

template<class dataType>
dataType Queue<dataType>::last_element() {
    return list.back();
}

///////////////////////////////////////

template<class dataType>
int Queue<dataType>::size() {
    return list.size();
}
