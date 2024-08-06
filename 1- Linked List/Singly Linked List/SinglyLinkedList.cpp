// ==================== Implementation ===================
// =======================================================
#include "SinglyLinkedList.h"
#include <cassert>
#include <iostream>
using namespace std;

template<class dataType>
SinglyLinkedList<dataType> :: SinglyLinkedList() {
    head = tail = nullptr ;
    len = 0 ;
}

/////////////////////////////////////////////////

template<class dataType>
SinglyLinkedList<dataType> :: ~SinglyLinkedList() {
    clear();
}

/////////////////////////////////////////////////

template<class dataType >
bool SinglyLinkedList<dataType> :: isEmpty() const {
    return head == nullptr;
}

/////////////////////////////////////////////////

template<class dataType>
void SinglyLinkedList<dataType> :: insertAtTail(const dataType &element) {
    Node<dataType>* newItem = new Node(element) ;

    if (head == nullptr)
        head = tail = newItem ;
    else {
        tail->next = newItem ;
        tail = newItem ;
    }
    len++ ;
}

/////////////////////////////////////////////////

template<class dataType>
void SinglyLinkedList<dataType>::insertAtHead(const dataType &element) {
    Node<dataType>* newItem = new Node(element) ;

    if (head == nullptr)
        head = tail = newItem ;
    else {
        newItem->next = head ;
        head = newItem ;
    }
    len++ ;
}

/////////////////////////////////////////////////

template<class dataType>
void SinglyLinkedList<dataType>::insertAt(const dataType &element, int index) {
    Node<dataType>* newItem = new Node(element) ;

    assert(index >= 0 && index < len);

    if (index == 0) {
        insertAtHead(element) ;
        return;
    }

    if (index == len - 1 ) {
        insertAtTail(element);
        return;
    }

    Node<dataType>* prev = nullptr ;
    Node<dataType>* curr = head ;
    for (int pos = 0 ; curr ; prev = curr , curr = curr->next , pos++) {
        if (pos == index) {
            prev->next = newItem ;
            newItem->next = curr ;
            len++ ;
            return ;
        }
    }
}

/////////////////////////////////////////////////

template<class dataType>
void SinglyLinkedList<dataType>::removeHead() {
    assert(len != 0) ;

    if (len == 1) {
        delete head ;
        head = tail = nullptr;
        len-- ;
        return;
    }
    Node<dataType>* curr = head ;
    head = head->next ;
    delete curr ;
    len-- ;
}

/////////////////////////////////////////////////

template<class dataType>
void SinglyLinkedList<dataType>::removeTail() {
    assert(len != 0) ;

    if (len == 1) {
        delete head ;
        head = tail = nullptr;
        len-- ;
        return;
    }

    Node<dataType>* prev = head ;
    for ( ; prev ; prev = prev->next) {
        if (prev->next == tail ) {
            delete tail ;
            tail = prev ;
            tail->next = nullptr ;
            len-- ;
            return ;
        }
    }
}

/////////////////////////////////////////////////

template<class dataType>
void SinglyLinkedList<dataType> ::removeAt(int index) {

    assert(index >= 0 && index < len );

    if (index == 0) {
        removeHead();
        return;
    }

    if (index == len - 1) {
        removeTail();
        return;
    }


    Node<dataType>* prev = nullptr ;
    Node<dataType>* curr = head ;
    for ( int pos = 0 ; curr ; prev = curr , curr = curr->next , pos++ ) {
        if (pos == index ) {
            prev->next = curr->next ;
            delete curr ;
            break;
        }
        len-- ;
    }

}

/////////////////////////////////////////////////

template<class dataType>
void SinglyLinkedList<dataType> :: swapDataByIndex(int firstIndex, int secondIndex) {
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

////////////////////////////////////////////////////

template<class dataType >
void SinglyLinkedList<dataType> :: replaceAt(const dataType& newElement, int index) {
    if (index < 0 || index >= len)
        return ;

    Node<dataType>* curr = head;
    for (int pos = 0; curr; curr = curr->next, pos++) {
        if (pos == index) {
            curr->data = newElement;
            return;
        }
    }
}

/////////////////////////////////////////////////

template<class dataType >
dataType SinglyLinkedList<dataType> ::retrieveAt(int index) {
    // used assert not if Bcz i don't know what i will return
    assert(index >= 0 && index < len);

    Node<dataType>* curr = head;
    for (int pos = 0; curr; curr = curr->next, pos++) {
        if (pos == index) {
            return curr->data;
        }
    }
    return -1; // not exist
}

/////////////////////////////////////////////////

template<class dataType >
void SinglyLinkedList<dataType> ::clear() { // remove all nodes

    for (Node<dataType>* curr = head; curr; ) {
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
void SinglyLinkedList<dataType> :: print() const {
    assert(!isEmpty());

    for (Node<dataType>* curr = head; curr; curr = curr->next)
        cout << curr->data << " " ;
    cout << '\n' ;
}

/////////////////////////////////////////////////

template<class dataType >
bool SinglyLinkedList<dataType> :: isExist(const dataType& element) {
    assert(!isEmpty());

    for (Node<dataType>* curr = head; curr ; curr = curr->next) {
        if (curr->data == element)
            return true;
    }

    return false;
}

/////////////////////////////////////////////////

template<class dataType>
bool SinglyLinkedList<dataType> :: isItemAtEqual(const dataType& element, int index) {
    assert(index >= 0 && index < len );

    Node<dataType>* curr = head;
    for (int pos = 0; curr ; curr = curr->next, pos++) {
        if (pos == index) {
            return curr->data == element;
        }
    }
    return false;
}

/////////////////////////////////////////////////

template<class dataType>
int SinglyLinkedList<dataType> :: size() const {
    return len ;
}

/////////////////////////////////////////////////

template<class dataType>
void SinglyLinkedList<dataType>::swap_head_tail() {
    assert(len != 0 && len != 1 );

    if (len == 2) {
        swap(head, tail) ;
        head->next = tail ;
        tail->next = nullptr ;
        return;
    }

    Node<dataType>* prev = head ;
    while (prev->next != tail) { // before tail
        prev = prev->next ;
    }

    tail->next = head->next ;
    head->next = nullptr ;
    prev->next = head ;

    swap(head , tail ) ;
}

/////////////////////////////////////////////////
// input  -> 6 10 8 15    k = 2
// output -> 8 15 6 10

template<class dataType>
void SinglyLinkedList<dataType> :: left_rotate(int k) {
    if (len == 1 || k % len == 0)
        return ;

    k %= len ;
    Node<dataType> * curr = head ;
    int n = len - k - 1 ; // position of must be tail

    while (n--)
        curr = curr->next ;

    tail->next = head ;
    head = curr->next ;
    curr->next = nullptr ;
}

/////////////////////////////////////////////////

template<class dataType>
void SinglyLinkedList<dataType> :: removeNextNode(Node<dataType>* prev) {
    Node<dataType>* toDelete = prev->next ;
    bool isTail = (prev->next == tail) ;

    prev->next = prev->next->next ;
    delete toDelete ;

    if (isTail)
        tail = prev ;
}

/////////////////////////////////////////////////

template<class dataType>
void SinglyLinkedList<dataType> :: remove_duplicates() { // O(n^2) time - O(1) memory
    if (len <= 1)
        return ;

    Node<dataType>* curr1 , *curr2 , *prev ;
    for (curr1 = head ; curr1 ; curr1 = curr1->next) {

        for (curr2 = curr1->next , prev = curr1 ; curr2 ; ) {

            if (curr1->data == curr2->data) {
                removeNextNode(prev) ;
                curr2 = prev->next ;
            }
            else {
                prev = curr2 ;
                curr2 = curr2->next ;
            }

        }

    }
}

/////////////////////////////////////////////////

template<class dataType>
void SinglyLinkedList<dataType> :: removeLastOccurance(int key) {
    if (len == 0)
        return ;

    int index = 0 , pos = 0 ;
    for (Node<dataType>* curr = head ; curr ; curr = curr->next , pos++ ) {
        if (curr->data == key) {
            index = pos ;
        }
    }
    removeAt(index) ;
}

/////////////////////////////////////////////////

template<class dataType>
void SinglyLinkedList<dataType>::moveToBack(int key) {

    if(len <= 1 )
        return ;

    Node<dataType>* curr = head ;
    int n = len ;
    for (Node<dataType>* prev = nullptr ;  n-- ; ) {
        if (curr->data == key) {
            if (curr == head) {
                Node<dataType>* item = curr ;
                head = head->next ;
                curr = head ;
                delete item ;
                item = nullptr ;
                prev = nullptr ;
            }
            else {
                removeNextNode(prev);
                curr = prev->next ;
            }
            insertAtTail(key) ;
        }
        else
             prev = curr , curr = curr->next ;
    }
}

/////////////////////////////////////////////////

template<class dataType>
int SinglyLinkedList<dataType> :: maxValue(Node<dataType>* head , bool is_first_call ) {

    // It is tricky to have function name same as standard
    // use std for standard and this-> for the class for clarity
    if (is_first_call)
        return this->maxValue(this->head, false);

    if (head == nullptr)
        return INT_MIN;		// initial min value
    return max(head->data, this->maxValue(head->next, false));

}

/////////////////////////////////////////////////

template<class dataType>
dataType SinglyLinkedList<dataType> :: findMiddel() {
    assert(head) ;
    // Without using len

    Node<dataType>* first = head , * second = head ;
    while (first && first->next) {
        first = first->next->next ; // when it arrive end the second will be middel
        second = second->next ;
    }
    return second->data ;
}