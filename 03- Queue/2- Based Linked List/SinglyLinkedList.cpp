// ==================== Implementation ===================
// =======================================================
#include "SinglyLinkedList.h"
#include <cassert>
#include <iostream>
using namespace std;

template<class dataType>
SinglyLinkedList<dataType>::SinglyLinkedList() {
    head = tail = nullptr;
    len = 0;
}

/////////////////////////////////////////////////

template<class dataType>
SinglyLinkedList<dataType>::~SinglyLinkedList() {
    clear();
}

/////////////////////////////////////////////////

template<class dataType>
bool SinglyLinkedList<dataType>::isEmpty() const {
    return head == nullptr;
}

/////////////////////////////////////////////////

template<class dataType>
void SinglyLinkedList<dataType>::insertAtTail(const dataType &element) {
    Node<dataType>* newItem = new Node<dataType>(element);

    if (head == nullptr)
        head = tail = newItem;
    else {
        tail->next = newItem;
        tail = newItem;
    }
    len++;
}

/////////////////////////////////////////////////

template<class dataType>
void SinglyLinkedList<dataType>::removeHead() {
    assert(len != 0);

    if (len == 1) {
        delete head;
        head = tail = nullptr;
        len--;
        return;
    }
    Node<dataType>* curr = head;
    head = head->next;
    delete curr;
    len--;
}

/////////////////////////////////////////////////

template<class dataType>
void SinglyLinkedList<dataType>::clear() { // remove all nodes
    while (!isEmpty()) {
        removeHead();
    }
}

/////////////////////////////////////////////////

template<class dataType>
dataType SinglyLinkedList<dataType>::front() {
    assert(len != 0);
    return head->data;
}

/////////////////////////////////////////////////

template<class dataType>
dataType SinglyLinkedList<dataType>::back() {
    assert(len != 0);
    return tail->data;
}

/////////////////////////////////////////////////

template<class dataType>
void SinglyLinkedList<dataType>::print() const {
    assert(!isEmpty());

    for (Node<dataType>* curr = head; curr; curr = curr->next)
        cout << curr->data << " ";
    cout << '\n';
}

/////////////////////////////////////////////////

template<class dataType>
int SinglyLinkedList<dataType>::size() const {
    return len;
}
