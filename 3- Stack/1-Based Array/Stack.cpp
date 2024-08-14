
#include "Stack.h"
#include <iostream>
#include <cassert>
using namespace std;

template<class dataType>
Stack<dataType>::Stack(int size) {
    length = size ;
    top = 0 ;
    arr = new dataType[size] ;
}

/////////////////////////////////////////

template<class dataType>
Stack<dataType>::~Stack() {
    delete[] arr ;
}

/////////////////////////////////////////

template<class dataType>
bool Stack<dataType> :: isFull() {
    return top  == length ;
}

/////////////////////////////////////////

template<class dataType>
bool Stack<dataType> :: isEmpty() {
    return top == 0 ;
}

/////////////////////////////////////////

template<class dataType>
void Stack<dataType> :: push(dataType element) {
    assert(!isFull()) ;
    arr[top] = element ;
    top++ ;
}

/////////////////////////////////////////

template<class dataType>
void Stack<dataType>::pop() {
    assert(!isEmpty()) ;
    arr[--top] = -1 ;
}

/////////////////////////////////////////

template<class dataType>
dataType Stack<dataType>::peek() {
    assert(!isEmpty()) ;
    int pos = top ;
    return arr[--pos] ;
}

/////////////////////////////////////////

template<class dataType>
void Stack<dataType>::print() {
    assert(!isEmpty());
    for (int i = top - 1 ; i >= 0 ; i--)
        cout << arr[i] << ' ' ;
    cout << '\n' ;
}

/////////////////////////////////////////



