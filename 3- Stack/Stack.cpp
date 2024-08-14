
#include "Stack.h"
#include <iostream>
#include <cassert>
#include <algorithm>
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
    arr[top++] = element ;
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

template<class dataType>
string Stack<dataType>::reverse_subwords(string str) {
    Stack<dataType> st(str.size()) ;
    string res = "" ;
    for (auto c : str) {
        if (c == ' ') {
            while (!st.isEmpty()) {
                res += st.peek() ;
                st.pop();
            }
            res += ' ' ;
        }
        else
            st.push(c) ;
    }

    return res ;
}

/////////////////////////////////////////

template<class dataType>
string Stack<dataType>::reverse_numbers(int number) {
    string str = to_string(number) ;
    Stack<dataType> st(str.size()) ;
    string res = "" ;

    for (auto c : str)
        st.push(c) ;

    while (!st.isEmpty()) {
        res += st.peek() ;
        st.pop() ;
    }

    return res ;
}

/////////////////////////////////////////

template<class dataType>
bool Stack<dataType>::isValidParentheses(string str ) {
    Stack<char> st(str.size()) ;

    for (auto c : str ) {
        if (c == '(' || c == '[' || c == '{')
            st.push(c) ;
        else {
            if ( !st.isEmpty() && c == '}' && st.peek() == '{')
                st.pop();
            else if (!st.isEmpty() && c == ']' && st.peek() == '[')
                st.pop();
            else if (!st.isEmpty() && c == ')' && st.peek() == '(')
                st.pop() ;
            else
                return false ;
        }
    }

    return st.isEmpty() ;
}

/////////////////////////////////////////

template<class dataType>
string Stack<dataType>::removeAdjacentDuplicates(string str ) {
    Stack<char> st(str.size()) ;

    for (auto c : str ) {
        if (st.isEmpty())
            st.push(c) ;
        else {
            if (!st.isEmpty() && st.peek() == c )
                st.pop();
            else
                st.push(c) ;
        }
    }

    string res = "" ;
    while (!st.isEmpty()) {
        res = st.peek() + res ;
        st.pop() ;
    }

    return res ;
}








