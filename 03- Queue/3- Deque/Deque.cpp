#include "Deque.h"
#include <cassert>
#include <iostream>
using namespace std ;

template<class dataType>
Deque<dataType>::Deque(int size ) {
    front = rear = added_elements = 0 ;
    length = size ;
    arr = new dataType[size] ;
}

/////////////////////////////////////////////////

template<class dataType>
Deque<dataType>::~Deque() {
    clear() ;
}

/////////////////////////////////////////////////

template<class dataType>
bool Deque<dataType>::isEmpty() {
    return added_elements == 0 ;
}

/////////////////////////////////////////////////

template<class dataType>
bool Deque<dataType>::isFull() {
    return added_elements == length ;
}

/////////////////////////////////////////////////

template<class dataType>
int Deque<dataType> :: next(int pos ) {
    return (pos + 1 ) % length ;
}

/////////////////////////////////////////////////

template<class dataType>
int Deque<dataType> :: prev(int pos ) {
    return pos - 1 == -1 ? length - 1 : pos - 1 ;
}

/////////////////////////////////////////////////

template<class dataType>
void Deque<dataType>::enqueue_front(dataType ele) {
    assert(!isFull());
    front = prev(front) ;
    arr[front] = ele ;
    added_elements++ ;
}

/////////////////////////////////////////////////

template<class dataType>
void Deque<dataType>::enqueue_back(dataType ele) {
    assert(!isFull());
    arr[rear] = ele ;
    rear = next(rear) ;
    added_elements++ ;
}

/////////////////////////////////////////////////

template<class dataType>
void Deque<dataType>::dequeue_front() {
    assert(!isEmpty());
    front = next(front) ;
    added_elements-- ;
}

/////////////////////////////////////////////////

template<class dataType>
void Deque<dataType>::dequeue_back() {
    assert(!isEmpty());
    rear = prev(rear) ;
    added_elements-- ;
}

/////////////////////////////////////////////////

template<class dataType>
dataType Deque<dataType> :: get_front() {
    assert(!isEmpty()) ;
    return arr[front] ;
}

/////////////////////////////////////////////////

template<class dataType>
dataType Deque<dataType> :: get_back() {
    assert(!isEmpty());
    int pos = prev(rear) ;
    return arr[pos] ;
}

/////////////////////////////////////////////////

template<class dataType>
void Deque<dataType> :: print() {
    assert(!isEmpty()) ;

    for (int i = front , j = 0 ; j < added_elements ; j++ , i = next(i))
        cout << arr[i] << ' ' ;
    cout << '\n' ;
}

/////////////////////////////////////////////////

template<class dataType>
void Deque<dataType> :: clear() {
    delete[] arr ;
}














