#ifndef BINARYHEAP_H
#define BINARYHEAP_H


template<class dataType>
class BinaryHeap {
protected: // to inherit this class for Min and Max Heap classes
    dataType *arr ;
    int top ;
    int capacity ;

    int parent(int pos ) ;
    int leftChild(int pos ) ;
    int rightChild(int pos ) ;

    virtual void heapifyUp(int childPos) = 0 ;
    virtual void heapifyDown(int parentPos ) = 0;
    void resizeHeap() ;

public:
    BinaryHeap() ;
    ~BinaryHeap();
    void clear() ;
    int size() ;
    void insert(dataType value) ;
    void remove() ; // delete min element in min heap or max element in max heap
    bool isEmpty() ;
};


template<class dataType>
class MinHeap : public BinaryHeap<dataType>{
protected:
    void heapifyUp(int childPos);
    void heapifyDown(int parentPos);
public:
    void print() ;

};


template<class dataType>
class MaxHeap : public BinaryHeap<dataType>{
protected:
    void heapifyUp(int childPos);
    void heapifyDown(int parentPos);
public:
    void print() ;
};

#endif //BINARYHEAP_H
