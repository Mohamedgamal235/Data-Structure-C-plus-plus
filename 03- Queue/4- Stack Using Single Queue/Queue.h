
#ifndef QUEUE_H
#define QUEUE_H

template<class dataType>
class Queue {
private:
    int length = 0 ;
    int rear = 0 ;
    int top = 0 ;
    int added_elements = 0 ;
    dataType *arr {} ;
public:
    Queue(int length ) ;
    ~Queue() ;
    int next(int pos ) ;
    int prev(int pos) ;
    void enqueue(dataType val) ;
    void enqueue_front(dataType ele) ;
    dataType dequeue() ;
    void print();
    void clear();
    bool isEmpty();
    bool isFull() ;
    dataType first_element() ;
    dataType last_element() ;
    int size() ;
};


#endif //QUEUE_H
