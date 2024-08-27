
#ifndef DEQUE_H
#define DEQUE_H


template<class dataType>
class Deque {
private:
    int front ;
    int length ;
    int rear ;
    int added_elements ;
    dataType *arr ;
public:
    Deque(int size) ;
    ~Deque() ;
    void enqueue_front(dataType ele) ;
    void enqueue_back(dataType ele) ;
    void dequeue_front() ;
    void dequeue_back() ;
    void clear() ;
    void print() ;
    int next(int pos ) ;
    int prev(int pos ) ;
    int size() ;
    dataType get_front() ;
    dataType get_back() ;
    bool isEmpty() ;
    bool isFull() ;
};



#endif //DEQUE_H
