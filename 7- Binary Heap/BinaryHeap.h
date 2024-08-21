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

    virtual void heapifyUp(int childPos);
    virtual void heapifyDown(int childPos ) ;
    void resizeHeap() ;

public:
    BinaryHeap() ;
    ~BinaryHeap();
    void clear() ;
    int size() ; 
    void insert(dataType value) ;

};


template<class dataType>
class MinHeap : public BinaryHeap<dataType>{
protected:
    void heapifyUp(int childPos);
    void heapifyDown(int childPos);

};


template<class dataType>
class MaxHeap : public BinaryHeap<dataType>{
protected:
    void heapifyUp(int childPos);
    void heapifyDown(int childPos);
};

#endif //BINARYHEAP_H
