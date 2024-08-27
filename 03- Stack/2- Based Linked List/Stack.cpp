
#include "Stack.h"
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

template<class dataType>
Stack<dataType>::Stack() {}

/////////////////////////////////////////

template<class dataType>
Stack<dataType>::~Stack() {
    list.clear() ;
}

/////////////////////////////////////////

template<class dataType>
bool Stack<dataType> :: isEmpty() {
    return list.isEmpty() ;
}

/////////////////////////////////////////

template<class dataType>
void Stack<dataType> :: push(dataType element) {
    list.insertAtHead(element) ;
}

/////////////////////////////////////////

template<class dataType>
void Stack<dataType>::pop() {
    assert(!isEmpty()) ;
    list.removeHead();
}

/////////////////////////////////////////

template<class dataType>
dataType Stack<dataType>::peek() {
    assert(!isEmpty()) ;
    return list.front();
}

/////////////////////////////////////////

template<class dataType>
void Stack<dataType>::print() {
    list.print();
}



