#include "BinaryTree.h"
#include <iostream>
using namespace std;

// ================= Implementation Helper Functions ======================= //
// ========================================================================= //

template<class dataType>
void BinaryTree<dataType>::printInOrderHelper(Node<dataType>* curr) {
    if (!curr)
        return;
    printInOrderHelper(curr->left) ;
    cout << curr->data << ' ' ;
    printInOrderHelper(curr->right) ;
}

/////////////////////////////////////////////////

// ================= Implementation User Functions ========================= //
// ========================================================================= //

template<class dataType>
BinaryTree<dataType>::BinaryTree() {

}



template<class dataType>
BinaryTree<dataType>::~BinaryTree() {

}


template<class dataType>
void BinaryTree<dataType>::printInOrder() {

}

