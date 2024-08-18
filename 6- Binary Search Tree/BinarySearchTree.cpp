#include "BinarySearchTree.h"
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
            insert(curr->right);
    }
    else if (value < curr->data) {
        if (!curr->left)
            curr->left = new Node<dataType>(value) ;
        else
            insert(curr->left) ;
    }
}

// =======================


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
    insertHelper(root , value) ;
}

/////////////////////////////

















