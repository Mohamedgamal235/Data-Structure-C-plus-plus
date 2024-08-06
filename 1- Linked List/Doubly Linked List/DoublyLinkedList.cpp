// ==================== Implementation ===================
// =======================================================
#include "DoublyLinkedList.h"
#include <cassert>
#include <iostream>
using namespace std;

template<class dataType>
DoublyLinkedList<dataType>::DoublyLinkedList() {
    head = tail = nullptr ;
    len = 0 ;
}

/////////////////////////////////////////////////

template<class dataType>
DoublyLinkedList<dataType>::~DoublyLinkedList() {
    clear();
}

/////////////////////////////////////////////////

template<class dataType >
bool DoublyLinkedList<dataType> ::isEmpty() const {
    return head == nullptr;
}

/////////////////////////////////////////////////

template<class dataType>
void DoublyLinkedList<dataType>::insertAtHead(const dataType &element) {
    Node<dataType>* newItem = new Node(element);

    if (len == 0 )
        head = tail = newItem ;
    else {
        newItem->next = head ;
        head->prev = newItem ;
        head = newItem ;
    }
    len++ ;
}

/////////////////////////////////////////////////

template<class dataType>
void DoublyLinkedList<dataType> :: insertAtTail(const dataType& element) {
    Node<dataType>* newItem = new Node(element) ;

    if (head == nullptr)
        head = tail = newItem;
    else {
        newItem->prev = tail;
        tail->next = newItem;
        tail = newItem ;
    }
    len++;
}

/////////////////////////////////////////////////

template<class dataType>
void DoublyLinkedList<dataType> ::insertAt(const dataType& element, int index) {


    assert(index >= 0 && index < len);

    if (index == 0) {
        insertAtHead(element);
        return;
    }
    if (index == len - 1) {
        insertAtTail(element);
        return;
    }

    Node<dataType>* item = new Node<dataType>(element);
    int pos = 0 ;
    Node<dataType>* curr = head ;
    for ( ; curr ; pos++) {
        if (pos == index) {
            item->next = curr ;
            curr->prev->next = item ;
            item->prev = curr->prev ;
            len++ ;
            return;
        }
    }
}

/////////////////////////////////////////////////

template<class dataType>
void DoublyLinkedList<dataType> :: removeAtHead() {
    assert(len != 0);

    if (len == 1){
        head = tail = nullptr ;
        len = 0 ;
        return;
    }
    Node<dataType>* curr = head;
    head = head->next ;
    head->prev ;
    delete curr ;
    curr = nullptr ;
    len-- ;
}

/////////////////////////////////////////////////

template<class dataType>
void DoublyLinkedList<dataType>::removeAtTail() {
    assert(len != 0);

    if (len == 1){
        head = tail = nullptr ;
        len = 0 ;
        return;
    }
    Node<dataType>* curr = tail ;
    tail = tail->prev ;
    tail->next = nullptr ;
    delete curr ;
    curr = nullptr ;
    len--;
}

/////////////////////////////////////////////////

template<class dataType>
void DoublyLinkedList<dataType> :: removeAt(int index) {

    assert(index >= 0 && index < len ) ;

    if (index == 0) {
        removeAtHead();
        return;
    }
    if (index == (len - 1)) {
        removeAtTail();
        return;
    }
    int pos = 0 ;
    Node<dataType>* curr = head ;
    for (; curr ; curr = curr->next , pos++ ) {
        if (pos == index ) {
            curr->next->prev = curr->prev ;
            curr->prev->next = curr->next ;
            delete curr ;
            len-- ;
            return ;
        }
    }
}

/////////////////////////////////////////////////

template<class dataType>
void DoublyLinkedList<dataType> ::swapByIndex(int firstIndex, int secondIndex) {
    if (isEmpty() || len == 1) {
        return;
    }

    if (firstIndex == secondIndex)
        return;

    if (firstIndex < 0 || secondIndex < 0 || firstIndex > len || secondIndex > len)
        return;

    Node<dataType>* firstNode = head;
    Node<dataType>* secondNode = head;

    int firstPos = 0;
    while (firstNode) {

        if (firstIndex == firstPos)
            break;

        firstNode = firstNode->next;
        firstPos++;
    }

    int secondPos = 0;
    while (firstNode) {

        if (secondIndex == secondPos)
            break;

        secondNode = secondNode->next;
        secondPos++;
    }

    dataType temp = firstNode->data;
    firstNode->data = secondNode->data;
    secondNode->data = temp;
}

/////////////////////////////////////////////////

template<class dataType >
void DoublyLinkedList<dataType> ::replaceAt(const dataType& newElement, int index) {
    assert (index >= 0 && index < len);

    Node<dataType>* curr = head;
    for (int pos = 0 ; curr ; curr = curr->next, pos++) {
        if (pos == index) {
            curr->data = newElement;
            return;
        }
    }
}

/////////////////////////////////////////////////

template<class dataType >
dataType DoublyLinkedList<dataType> :: retrieveAt(int index) {
    assert (index >= 0 && index < len);

    Node<dataType>* curr = head;
    for (int pos = 0; curr; curr = curr->next, pos++) {
        if (pos == index) {
            return curr->data;
        }
    }
    return dataType() ; // not exist
}

/////////////////////////////////////////////////

template<class dataType >
void DoublyLinkedList<dataType> ::clear() { // remove all nodes

    for (Node<dataType>* curr = head; curr;) {
        Node<dataType>* toDelete = curr;
        curr = curr->next; // move to next before delete
        delete toDelete;
        toDelete = nullptr;
    }
    head = tail = nullptr;
    len = 0;
}

/////////////////////////////////////////////////

template<class dataType >
void DoublyLinkedList<dataType> ::print() const {
    assert(!isEmpty());

    for (Node<dataType>* curr = head; curr; curr = curr->next)
        cout << curr->data << " " ;
    cout << '\n' ;
}

/////////////////////////////////////////////////

template<class dataType >
void DoublyLinkedList<dataType> ::printReverse() const {
    assert(!isEmpty());

    for (Node<dataType>* curr = tail ; curr ; curr = curr->prev)
        cout << curr->data << " " ;
    cout << '\n' ;
}

/////////////////////////////////////////////////

template<class dataType >
bool DoublyLinkedList<dataType> ::isExist(const dataType& element) {
    if (!isEmpty()) {
        for (Node<dataType>* curr = head; curr; curr = curr->next) {
            if (curr->data == element)
                return true;
        }
    }
    return false;
}

/////////////////////////////////////////////////

template<class dataType>
bool DoublyLinkedList<dataType> ::isItemAtEqual(const dataType& element, int index) {
    assert (index >= 0 && index < len);

    Node<dataType>* curr = head;
    for (int pos = 0; curr; curr = curr->next, pos++) {
        if (pos == index) {
            return curr->data == element;
        }
    }
    return false;
}

/////////////////////////////////////////////////

template<class dataType >
int DoublyLinkedList<dataType> :: size() const {
    return len ;
}

/////////////////////////////////////////////////

template<class dataType>
void DoublyLinkedList<dataType> :: removeAllWithVaule(int val) {
    assert(len != 0 ) ;

    Node<dataType>* curr = head ;
    for (int pos = 0 ; curr ; ) {
        if (curr->data == val) {
            curr = curr->next ;
            removeAt(pos) ;
        }
        curr = curr->next ;
    }
}

/////////////////////////////////////////////////

template<class dataType>
bool DoublyLinkedList<dataType>::isPalindrome() {
    assert(len != 0);

    if (len == 1)
        return true ;

    Node<dataType>* left = head ;
    Node<dataType>* right = tail ;
    int sz = len / 2 ;
    for (; sz != 0 ; sz-- , left = left->next , right = right->prev) {
        if (left->data != right->data )
            return false ;
    }
    return true ;
}

/////////////////////////////////////////////////

template<class dataType>
void DoublyLinkedList<dataType> :: link(Node<dataType> *curr) {
    Node<dataType>* first = curr->prev , *second = curr->next ;
    if (first)
        first->next = second ;
    if (second)
        second->prev = first ;
}

/////////////////////////////////////////////////

template<class dataType>
void DoublyLinkedList<dataType> :: removeEvenPositions() {
    assert(len > 1) ;

    Node<dataType>* curr = head ;
    for (; curr && curr->next ; curr = curr->next) {
        Node<dataType>* toDelete = curr->next ;
        link(toDelete) ;
        if (!curr->next)
            tail = curr;

        delete toDelete ;
        toDelete = nullptr ;
    }
}

/////////////////////////////////////////////////

template<class dataType>
void DoublyLinkedList<dataType> :: removeOddPositions() {
    // we can make odd to even and delete even postions
    insertAtHead(100) ;
    removeEvenPositions();
    removeAtHead();
}

/////////////////////////////////////////////////

template<class dataType>
void DoublyLinkedList<dataType> :: reverse() {
    assert(len > 1 );

    Node<dataType>* first = head , *second = head->next ;
    while (second) {
        Node<dataType> * f = second, *s = second->next;
        // swapping
        if (second)
            second->next = first ;
        if (first)
            first->prev = second ;
        //---
        first = f , second = s ; // move to next nodes
    }
    swap(head , tail) ;
    head->prev = nullptr ;
    tail->next = nullptr ;
}

/////////////////////////////////////////////////

template<class dataType>
dataType DoublyLinkedList<dataType> :: findMiddel() {
    assert(head) ;

    Node<dataType>* first = head , * second = tail ;
    while (first != second && first->next != second) {
        first = first->next ;
        second = second->prev ;
    }
    return second->data ;
}

/////////////////////////////////////////////////

template<class dataType>
Node<dataType>* DoublyLinkedList<dataType> :: get_nth(int n ) {
    int cnt = 0 ;
    for (Node<dataType>* curr = head ; curr ; curr = curr->next , cnt++) {
        if (cnt == n)
            return curr ;
    }
    return nullptr ;
}

/////////////////////////////////////////////////

template<class dataType>
void DoublyLinkedList<dataType>::swap_kth_first_with_back(int k) {
    assert( k <= len ) ;
    int kth_back = len - k + 1 ;

    if (k == kth_back)
        return ;

    if (k > kth_back)
        swap(k , kth_back);

    Node<dataType>* first = get_nth(k) ;
    Node<dataType>* last = get_nth(kth_back) ;

    Node<dataType>* f_prev = first->prev ;
    Node<dataType>* f_next = first->next ;

    Node<dataType>* l_prev = last->prev ;
    Node<dataType>* l_next = last->next ;

    if (k + 1 == kth_back) {
        link(f_prev , last) ;
        link(last , first) ;
        link(first,l_next) ;
    }
    else {
        link(f_prev , last);
        link(last, f_next);

        link(l_prev , first);
        link(first , l_next) ;
    }
    if (k == 1 )
        swap(head , tail) ;
}

