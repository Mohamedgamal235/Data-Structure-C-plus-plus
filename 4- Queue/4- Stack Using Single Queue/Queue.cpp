#include "Queue.h"
#include <cassert>
#include <iostream>
using namespace std;

template<class dataType>
Queue<dataType>::Queue(int length) {
    this->length = length;
    arr = new dataType[length];
    top = 0;
    rear = 0;
    added_elements = 0;
}

///////////////////////////////////////

template<class dataType>
Queue<dataType>::~Queue() {
    clear();
}

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
int Queue<dataType>::next(int pos) {
    return (pos + 1) % length;
}

///////////////////////////////////////

template<class dataType>
int Queue<dataType>::prev(int pos) {
    return pos - 1 == -1 ? length - 1 : pos - 1;
}

///////////////////////////////////////

template<class dataType>
void Queue<dataType>::enqueue_front(dataType element) {
    assert(!isFull());
    top = prev(top) ;
    arr[top] = element ;
    added_elements++ ;
}

///////////////////////////////////////

template<class dataType>
void Queue<dataType>::enqueue(dataType element) {
    assert(!isFull());
    arr[rear] = element;
    rear = next(rear);
    added_elements++;
}

///////////////////////////////////////

template<class dataType>
dataType Queue<dataType>::dequeue() {
    assert(!isEmpty());
    dataType value = arr[top];
    top = next(top);
    added_elements--;
    return value;
}

///////////////////////////////////////

template<class dataType>
void Queue<dataType>::clear() {
    delete[] arr;
    arr = nullptr;
    added_elements = 0;
    top = rear = 0;
}

///////////////////////////////////////

template<class dataType>
void Queue<dataType>::print() {
    assert(!isEmpty());
    for (int curr = top, i = 0; i < added_elements; i++, curr = next(curr)) {
        cout << arr[curr] << ' ';
    }
    cout << '\n';
}

///////////////////////////////////////

template<class dataType>
dataType Queue<dataType>::first_element() {
    assert(!isEmpty());
    return arr[top];
}

///////////////////////////////////////

template<class dataType>
dataType Queue<dataType>::last_element() {
    assert(!isEmpty());
    int pos = prev(rear);
    return arr[pos];
}

///////////////////////////////////////

template<class dataType>
int Queue<dataType>::size() {
    return added_elements;
}
