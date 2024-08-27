
#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H
#include <iostream>

template<class T>
struct Node {
    T data;
    Node<T>* next;
    Node(const T& val) : data(val), next(nullptr) {}
};

template<class dataType>
class SinglyLinkedList {
private:
    Node<dataType>* head;
    Node<dataType>* tail;
    int len;
public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    void insertAtHead(const dataType& element);
    void removeHead();
    dataType front();
    void print() const;
    void clear();
    bool isEmpty() const;
    int size() const;
};

#endif //SINGLYLINKEDLIST_H
