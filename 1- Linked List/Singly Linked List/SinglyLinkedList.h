//
// Created by Mohamed Gamal on 04/08/2024.
//

#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H
#include <iostream>

template<class T>
struct Node {
    T data ;
    Node<T>* next ;
    Node(const T val) {
        data = val ;
        next = nullptr ;
    }
};

template<class dataType>
class SinglyLinkedList {
private:
    Node<dataType>* head ;
    Node<dataType>* tail ;
    int len ;
public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    void insertAtHead(const dataType& element);
    void insertAtTail(const dataType& element) ;
    void insertAt(const dataType& element , int index ) ;
    void removeHead();
    void removeTail();
    void removeAt(int index) ;
    int size() const;
    void print() const;
    void clear();
    bool isEmpty() const;
    //======================= Extra Functions if you more practice ============== // 
    void removeNextNode(Node<dataType>* prev) ;
    void removeLastOccurance(int key);
    void moveToBack(int key );
    int maxValue(Node<dataType>* head = nullptr , bool is_first_call = true);
    void replaceAt(const dataType& newElement, int index);
    dataType retrieveAt(int index);
    void swapDataByIndex(int firstIndex, int secondIndex);
    void swap_head_tail();
    void left_rotate(int k ) ;
    void remove_duplicates();
    bool isExist(const dataType& element);
    bool isItemAtEqual(const dataType& element, int index);
    dataType findMiddel();
    
};

#endif //SINGLYLINKEDLIST_H
