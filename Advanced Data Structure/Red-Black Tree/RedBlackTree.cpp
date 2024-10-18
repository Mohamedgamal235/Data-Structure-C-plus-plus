#include "RedBlackTree.h"


// ======================================================================================================== //
// ================================== Implementation Class Functions ====================================== //
// ======================================================================================================== //

// ============================================================ //
// ============== Implementation Helper Functions ============= //
// ============================================================ //


template<class dataType>
void RedBlackTree<dataType>::inOrder(Node<dataType> *curr) {
    if (!curr)
        return;

    inOrder(curr->left);
    cout << curr->data << ' ' ;
    inOrder(curr->right);
}

//----------------------

template<class dataType>
void RedBlackTree<dataType>::inPre(Node<dataType> *curr) {
    if (!curr)
        return;
    cout << curr->data << ' ';
    inPre(curr->left);
    inPre(curr->right);
}

//----------------------

template<class dataType>
void RedBlackTree<dataType>::inPost(Node<dataType> *curr) {
    if (!curr)
        return;
    inPost(curr->left);
    inPost(curr->right);
    cout << curr->data << ' ';
}

//----------------------

template<class dataType>
Node<dataType>* RedBlackTree<dataType>::leftRotation(Node<dataType> *parent) {
    Node<dataType>* child = parent->right;
    parent->right = child->left;
    child->left = parent;
    return child;
}

//----------------------

template<class dataType>
Node<dataType>* RedBlackTree<dataType>::rightRotation(Node<dataType> *child) {
    Node<dataType>* parent = child->left;
    child->left = parent->right;
    parent->right = child;
    return parent;
}


//----------------------

template<class dataType>
Node<dataType>* RedBlackTree<dataType>::insertHelper(Node<dataType> *curr, dataType value) {
    if (!curr)
        return new Node<dataType>(value);

    if (value > curr->data)
        curr->right = insertHelper(curr->right , value );
    else if (value < curr->data)
        curr->left = insertHelper(curr->left , value) ;

    return curr ;
}

//----------------------

template<class dataType>
Node<dataType> *RedBlackTree<dataType>::getMaxHelper(Node<dataType>* curr) {
    if (!curr->right)
        return curr ;

    return maxHelper(curr->right) ;
}

//----------------------

template<class dataType>
Node<dataType> *RedBlackTree<dataType>::getMinHelper(Node<dataType>* curr) {
    if (!curr->left)
        return curr ;

    return maxHelper(curr->left) ;
}

//----------------------

template<class dataType>
void RedBlackTree<dataType>::clearHelper(Node<dataType> *curr) {
    if (!curr)
        return;

    clearHelper(curr->left) ;
    clearHelper(curr->right);
    delete curr ;
}


// ============================================================ //
// ============== Implementation user Functions =============== //
// ============================================================ //


template<class dataType>
RedBlackTree<dataType>::RedBlackTree() {
    root = nullptr ;
}

//----------------------

template<class dataType>
RedBlackTree<dataType>::~RedBlackTree() {
    clear();
}

//----------------------

template<class dataType>
void RedBlackTree<dataType>::insert(dataType value) {
    root = insertHelper(root , value ) ;
}

//----------------------

template<class dataType>
void RedBlackTree<dataType> :: clear() {
    if (!root) {
        cout << "Tree is already empty.\n" ;
        return;
    }
    clearHelper(root) ;
    root = nullptr ;
}