
#include "Stack.h"
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

template<class dataType>
Stack<dataType>::Stack(int size) {
    length = size ;
    top1 = 0 ;
    top2 = size - 1 ;
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
    return top1 > top2 ;
}

/////////////////////////////////////////

template<class dataType>
bool Stack<dataType> :: isEmpty() {
    return top1 == 0 && top2 == length - 1 ;
}

/////////////////////////////////////////

template<class dataType>
void Stack<dataType> :: push(int id  , dataType element) {
    assert(!isFull());
    if (id == 1 )
        arr[top1++] = element ;
    else
        arr[top2--] = element ;
}

/////////////////////////////////////////

template<class dataType>
void Stack<dataType> :: pop(int id ) {
    assert(!isEmpty());
    if (id == 1)
        top1-- ;
    else
        top2++ ;
}

/////////////////////////////////////////

template<class dataType>
dataType Stack<dataType>::peek(int id ) {
    assert(!isEmpty()) ;
    if (id == 1)
        return arr[top1 - 1 ] ;
    else
        return arr[top2 + 1 ] ;
}

/////////////////////////////////////////

template<class dataType>
void Stack<dataType>::print() {
    assert(!isEmpty());

    cout << "ID 1 : " ;
    for (int i = top1 - 1 ; i >= 0 ; i-- )
        cout << arr[i] << ' ' ;
    cout << '\n' ;

    cout << "ID 2 : " ;
    for (int i = top2 + 1 ; i < length ; i++ )
        cout << arr[i] << ' ' ;
    cout << '\n' ;
}










