#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

// ========================================================================= //
// ================= Implementation Helper Functions ======================= //
// ========================================================================= //

template<class dataType>
void BinarySearchTree<dataType>::insertHelper(Node<dataType> *curr, dataType value) {
    if (value > curr->data) {
        if (!curr->right)
            curr->right = new Node<dataType>(value) ;
        else
            insertHelper(curr->right , value );
    }
    else if (value < curr->data) {
        if (!curr->left)
            curr->left = new Node<dataType>(value) ;
        else
            insertHelper(curr->left , value) ;
    }
}

// =======================

template<class dataType>
void BinarySearchTree<dataType> :: inOrder(Node<dataType>* curr) {
    if (!curr)
        return;
    inOrder(curr->left);
    cout << curr->data << ' ' ;
    inOrder(curr->right);
}

// =======================

template<class dataType>
void BinarySearchTree<dataType>::inPre(Node<dataType> *curr) {
    if (!curr)
        return;
    cout << curr->data << ' ' ;
    inPre(curr->left) ;
    inPre(curr->right) ;
}

// =======================

template<class dataType>
void BinarySearchTree<dataType>::inPost(Node<dataType> *curr) {
    if (!curr)
        return;
    inPost(curr->left) ;
    inPost(curr->right) ;
    cout << curr->data << ' ' ;
}

// =======================

template<class dataType>
void BinarySearchTree<dataType>::clearHelper(Node<dataType> *curr) {

}

// =======================

template<class dataType>
bool BinarySearchTree<dataType>::searchHelper(Node<dataType> *curr , dataType value ) {
    if (curr->data == value)
        return true ;

    if (curr->data > value)
        return curr->left && searchHelper(curr->left , value);

    return curr->right && searchHelper(curr->right , value) ;
}

// =======================

template<class dataType>
dataType BinarySearchTree<dataType>::getMinHelper(Node<dataType> *curr) {
    if (!curr->left)
        return curr->data ;

    return getMinHelper(curr->left) ;
}

// =======================

template<class dataType>
dataType BinarySearchTree<dataType>::getMaxHelper(Node<dataType> *curr) {
    if (!curr->right)
        return curr->data ;

    return getMaxHelper(curr->right) ;
}

// ========================================================================= //
// ================= Implementation User Functions ========================= //
// ========================================================================= //

template<class dataType>
BinarySearchTree<dataType>::BinarySearchTree() {
    root = nullptr ;
}

/////////////////////////////

template<class dataType>
BinarySearchTree<dataType>::~BinarySearchTree() {
    // clear();
}

/////////////////////////////

template<class dataType>
bool BinarySearchTree<dataType> :: isEmpty() {
    return root == nullptr ;
}

/////////////////////////////

template<class dataType>
void BinarySearchTree<dataType>::insert(dataType value) {
    if (isEmpty())
        root = new Node<dataType>(value) ;
    else
        insertHelper(root , value) ;
}

/////////////////////////////

template<class dataType>
bool BinarySearchTree<dataType>::isExist(dataType value) {
    return searchHelper(root , value) ;
}

/////////////////////////////

template<class dataType>
dataType BinarySearchTree<dataType>::getMin() {
    return getMinHelper(root) ;
}

/////////////////////////////

template<class dataType>
dataType BinarySearchTree<dataType>::getMax() {
    return getMaxHelper(root) ;
}

/////////////////////////////

template<class dataType>
void BinarySearchTree<dataType>::printInOrder() {
    if (isEmpty()) {
        cout << "Tree is empty\n";
        return;
    }
    inOrder(root);
}

/////////////////////////////

template<class dataType>
void BinarySearchTree<dataType>::printInPostOrder() {
    if (isEmpty()) {
        cout << "Tree is empty\n";
        return;
    }
    inPost(root);
}

/////////////////////////////

template<class dataType>
void BinarySearchTree<dataType>::printInPreOrder() {
    if (isEmpty()) {
        cout << "Tree is empty\n";
        return;
    }
    inPre(root);
}

template<class dataType>
void BinarySearchTree<dataType> :: clear() {
    clear(root) ;
}














