#include "BinaryHeap.h"
#include <iostream>
#include <cassert>
using namespace std;

// ======================================================================================================== //
// ================================== Implementation Helper Functions ======================================= //
// ======================================================================================================== //

template<class dataType>
int BinaryHeap<dataType>::parent(int pos) {
    return (pos - 1 ) / 2 ;
}

//========

template<class dataType>
int BinaryHeap<dataType>::leftChild(int pos) {
    return 2 * pos + 1 ;
}

//========

template<class dataType>
int BinaryHeap<dataType>::rightChild(int pos) {
    return 2 * pos + 2  ;
}

//========

template<class dataType>
void BinaryHeap<dataType>::resizeHeap() {
    capacity *= 2;

    dataType* newArr = new dataType[capacity];

    for (int i = 0; i < top; i++) {
        newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
}


// ============================== //
// ======== For Min Heap ======== //
// ============================== //

template<class dataType>
void MinHeap<dataType> :: heapifyUp(int childPos) {

    int pos = this->parent(childPos) ;
    if (childPos == 0  || this->arr[pos] < this->arr[childPos])
        return;

    swap(this->arr[pos] , this->arr[childPos]);
    heapifyUp(pos);
}

//===============

template<class dataType>
void MinHeap<dataType>::heapifyDown(int parentPos) {
    int leftPos = this->leftChild(parentPos) ;
    int rightPos = this->rightChild(parentPos) ;

    int smallestPos = parentPos ;
    if (this->arr[smallestPos] > this->arr[leftPos])
        smallestPos = leftPos ;

    if (this->arr[smallestPos] > this->arr[rightPos])
        smallestPos = rightPos ;

    if (smallestPos != parentPos) {
        swap(this->arr[smallestPos] , this->arr[parentPos]) ;
        heapifyDown(smallestPos);
    }
}


// ============================== //
// ======== For Max Heap ======== //
// ============================== //

template<class dataType>
void MaxHeap<dataType> :: heapifyUp(int childPos) {

    int pos = this->parent(childPos) ;
    if (childPos == 0  || this->arr[pos] > this->arr[childPos])
        return;

    swap(this->arr[pos] , this->arr[childPos]);
    heapifyUp(pos);
}

//===============

template<class dataType>
void MaxHeap<dataType>::heapifyDown(int parentPos) {
    int leftPos = this->leftChild(parentPos) ;
    int rightPos = this->rightChild(parentPos) ;


    int largestPos = parentPos ;
    if (this->arr[largestPos] < this->arr[leftPos])
        largestPos = leftPos ;

    if (this->arr[largestPos] < this->arr[rightPos])
        largestPos = rightPos ;

    if (largestPos != parentPos) {
        swap(this->arr[largestPos] , this->arr[parentPos]) ;
        heapifyDown(largestPos);
    }
}


// ======================================================================================================== //
// ================================== Implementation User Functions ======================================= //
// ======================================================================================================== //

template<class dataType>
BinaryHeap<dataType>::BinaryHeap() {
    capacity = 1000 ;
    arr = new dataType [capacity] ;
    top = 0 ;
}

////////////////////////////////////

template<class dataType>
BinaryHeap<dataType>::~BinaryHeap() {
    clear() ;
}

////////////////////////////////////

template<class dataType>
void BinaryHeap<dataType>::insert(dataType value) {
    if (top == capacity)
        resizeHeap();
    arr[top] = value ;
    heapifyUp(top) ;
    top++ ;
}

////////////////////////////////////

template<class dataType>
void BinaryHeap<dataType> :: remove() {
    if (isEmpty()) {
        cout << "Heap is empty!\n" ;
        return ;
    }
    arr[0] = arr[top-1] ;
    top-- ;
    heapifyDown(0) ;
}

template<class dataType>
bool BinaryHeap<dataType>::isEmpty() {
    return (top == 0 );
}

////////////////////////////////////

template<class dataType>
int BinaryHeap<dataType> :: size() {
    return top ;
}

////////////////////////////////////

template<class dataType>
void BinaryHeap<dataType> :: clear() {
    delete[] arr ;
    top = 0 ;
}

////////////////////////////////////


// ============================== //
// ======== For Max Heap ======== //
// ============================== //

template<class dataType>
void MaxHeap<dataType>::print() {
    if (this->isEmpty()) {
        cout << "Heap is empty!\n" ;
        return ;
    }
    for (int i = 0 ; i < this->top ; i++)
        cout << this->arr[i] << ' ' ;
    cout << '\n' ;
}

// ============================== //
// ======== For Min Heap ======== //
// ============================== //

template<class dataType>
void MinHeap<dataType>::print() {
    if (this->isEmpty()) {
        cout << "Heap is empty!\n" ;
        return ;
    }
    for (int i = 0 ; i < this->top ; i++)
        cout << this->arr[i] << ' ' ;
    cout << '\n' ;
}













