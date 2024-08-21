#include "BinaryHeap.h"
#include <iostream>
using namespace std;

// ========================================================================= //
// ================= Implementation Helper Functions ======================= //
// ========================================================================= //

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


// ========================================================================= //
// ================= Implementation User Functions ========================= //
// ========================================================================= //

template<class dataType>
BinaryHeap<dataType>::BinaryHeap() {
    capacity = 1000 ;
    arr = new dataType [capacity] ;
    size = 0 ;
}

template<class dataType>
BinaryHeap<dataType>::~BinaryHeap() {
    clear() ;
}


template<class dataType>
void BinaryHeap<dataType>::insert(dataType value) {
    if (top == capacity)
        resizeHeap();
    arr[top] = value ;
    top++ ;
    heapifyUp(0) ;
}

template<class dataType>
int BinaryHeap<dataType> :: size() {
    return top ;
}


template<class dataType>
void BinaryHeap<dataType> :: clear() {
    delete[] arr ;
    top = 0 ;
}















