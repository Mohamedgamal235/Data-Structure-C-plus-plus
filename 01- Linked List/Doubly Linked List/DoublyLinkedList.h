#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

template<class T>
struct Node {
    T data ;
    Node<T>* next ;
    Node<T>* prev ;
    Node(const T val) {
        data = val ;
        prev = next = nullptr ;
    }
};

template<class dataType>
class DoublyLinkedList {
private:
    Node<dataType>* head ;
    Node<dataType>* tail ;
    int len = 0 ;
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insertAtHead(const dataType& element);
    void insertAtTail(const dataType& element);
    void insertAt(const dataType& element, int index);
    void removeAtHead();
    void removeAtTail();
    void removeAt(int index);
    void removeAllWithVaule(int val);
    void removeEvenPositions();
    void removeOddPositions() ;
    void link(Node<dataType>* curr) ;
    void reverse() ;
    void replaceAt(const dataType& newElement, int index);
    void print() const;
    void printReverse() const ;
    void swapByIndex(int firstIndex, int secondIndex);
    void swap_kth_first_with_back(int k) ;
    void clear();
    // -------------
    bool isExist(const dataType& element);
    bool isItemAtEqual(const dataType& element, int index);
    bool isEmpty() const;
    bool isPalindrome();
    // -------------
    Node<dataType>* get_nth(int n );
    dataType retrieveAt(int index);
    dataType findMiddel();
    int size() const;
};


#endif //DOUBLYLINKEDLIST_H
