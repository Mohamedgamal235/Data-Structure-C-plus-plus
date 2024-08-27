
#include "Stack.h"
#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
using namespace std;

template<class dataType>
Stack<dataType>::Stack(int size) : q(size){ ;
    added_elements = 0 ;
}

///////////////////////////////////////////////////////////////////////

template<class dataType>
Stack<dataType>::~Stack() {
    q.clear() ;
}

///////////////////////////////////////////////////////////////////////

template<class dataType>
bool Stack<dataType> :: isEmpty() {
    return q.isEmpty();
}

///////////////////////////////////////////////////////////////////////

template<class dataType>
void Stack<dataType> :: push(dataType element) {
    q.enqueue_front(element) ;
    added_elements++ ;
}

///////////////////////////////////////////////////////////////////////

template<class dataType>
void Stack<dataType>::pop() {
    assert(!isEmpty()) ;
    q.dequeue() ;
    added_elements-- ;
}

///////////////////////////////////////////////////////////////////////

template<class dataType>
dataType Stack<dataType>::peek() {
    assert(!isEmpty()) ;
    return q.first_element() ;
}

///////////////////////////////////////////////////////////////////////

template<class dataType>
void Stack<dataType> :: print() {
    assert(!isEmpty()) ;
    q.print();
}





