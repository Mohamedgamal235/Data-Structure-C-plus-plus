#include "BinaryTree.h"
#include <iostream>
#include <cassert>
using namespace std;

// ========================================================================= //
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

// ============================

template<class dataType>
void BinaryTree<dataType>::printInPostOrderHelper(Node<dataType>* curr) {
    if (!curr)
        return;
    printInPostOrderHelper(curr->left) ;
    printInPostOrderHelper(curr->right) ;
    cout << curr->data << ' ' ;
}

// ============================

template<class dataType>
void BinaryTree<dataType>::printInPreOrderHelper(Node<dataType>* curr) {
    if (!curr)
        return;
    cout << curr->data << ' ' ;
    printInPreOrderHelper(curr->left) ;
    printInPreOrderHelper(curr->right) ;
}

// ============================

template<class dataType>
dataType BinaryTree<dataType>::maxElementHelper(Node<dataType>* curr) {
    if (!curr)
        return dataType() ;

    dataType leftMax = maxElementHelper(curr->left) ;
    dataType rightMax = maxElementHelper(curr->right) ;

    return max(curr->data , max(leftMax , rightMax)) ;
}

// ============================

template<class dataType>
int BinaryTree<dataType>::heightOfTreeHelper(Node<dataType> * curr) {
    if (!curr)
        return -1 ;

    int h1 = 1 + heightOfTreeHelper(curr->left) ;
    int h2 = 1 + heightOfTreeHelper(curr->right) ;

    return max(h1 , h2 ) ;
}

// ============================

template<class dataType>
int BinaryTree<dataType>::numberOfNodesHelper(Node<dataType>* curr) {
    if (!curr)
        return 0 ;
    int sub1 = numberOfNodesHelper(curr->left) ;
    int sub2 = numberOfNodesHelper(curr->right) ;

    return 1 + sub1 + sub2 ;
}

// ============================




// ========================================================================= //
// ================= Implementation User Functions ========================= //
// ========================================================================= //

template<class dataType>
BinaryTree<dataType>::BinaryTree(const dataType &val) {
    root = new Node<dataType>(val) ;
}

//////////////////////////

template<class dataType>
BinaryTree<dataType>::~BinaryTree() {

}

//////////////////////////

template<class dataType>
void BinaryTree<dataType>::printInOrder() {
    printInOrderHelper(root) ;
    cout << '\n' ;
}

//////////////////////////

template<class dataType>
void BinaryTree<dataType>::printInPostOrder() {
    printInPostOrderHelper(root) ;
    cout << '\n' ;
}

//////////////////////////

template<class dataType>
void BinaryTree<dataType>::printInPreOrder() {
    printInPreOrderHelper(root) ;
    cout << '\n' ;
}

//////////////////////////

template<class dataType>
void BinaryTree<dataType>::insert(const vector<dataType> &values, const vector<char> &direction) {
    assert(values.size() == direction.size()) ;

    Node<dataType>* curr = this->root ;

    for (int i = 0 ; i < direction.size() ; i++) {
        if (direction[i] == 'L') {
            if (curr->left == nullptr)
                curr->left = new Node(values[i] );
            else
                assert(curr->left->data == values[i]);
            curr = curr->left ;
        }
        else if ( direction[i] == 'R' ){
            if (curr->right == nullptr)
                curr->right = new Node(values[i]) ;
            else
                assert(curr->right->data == values[i]) ;
            curr = curr->right ;
        }
        else {
            cout << "Invalid diraction : " << direction[i] << '\n' ;
            return ;
        }
    }
}

//////////////////////////

template<class dataType>
dataType BinaryTree<dataType>::maxElement() {
    return maxElementHelper(root) ;
}

//////////////////////////

template<class dataType>
int BinaryTree<dataType>::heightOfTree() {
    return heightOfTreeHelper(root) ;
}

//////////////////////////

template<class dataType>
int BinaryTree<dataType> :: numberOfNodes() {
    return numberOfNodesHelper(root) ;
}






