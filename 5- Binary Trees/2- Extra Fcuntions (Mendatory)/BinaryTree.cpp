#include "BinaryTree.h"
#include <iostream>
#include <cassert>
#include <queue>
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

template<class dataType>
int BinaryTree<dataType> :: numberOfLeavesHelper(Node<dataType> *curr) {
    if (!curr) // if tree is empty
        return 0 ;

    if (!curr->left && !curr->right)
        return 1 ;

    int sub1 = numberOfLeavesHelper(curr->left) ;
    int sub2 = numberOfLeavesHelper(curr->right);

    return sub1 + sub2 ;
}

// ============================

template<class dataType>
bool BinaryTree<dataType> :: isExistHepler(Node<dataType> *curr , dataType value ) {
    if (!curr)
        return false ;

    if (curr->data == value)
        return true ;

    return isExistHepler(curr->left, value) || isExistHepler(curr->right, value)  ;
}

// ============================

template<class dataType>
void BinaryTree<dataType>::clearHelper(Node<dataType> *curr) {
    if (!curr)
        return ;

    clearHelper(curr->left) ;
    clearHelper(curr->right) ;

    delete curr ;
    curr = nullptr ;
}


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
    clearHelper(root) ;
}

//////////////////////////

template<class dataType>
bool BinaryTree<dataType> :: isEmpty() {
    return root == nullptr ;
}

template<class dataType>
void BinaryTree<dataType>::printInOrder() {
    if (isEmpty()) {
        cout << "The Tree is Empty\n" ;
        return;
    }
    printInOrderHelper(root) ;
    cout << '\n' ;
}

//////////////////////////

template<class dataType>
void BinaryTree<dataType>::printInPostOrder() {
    if (isEmpty()) {
        cout << "The Tree is Empty\n" ;
        return;
    }
    printInPostOrderHelper(root) ;
    cout << '\n' ;
}

//////////////////////////

template<class dataType>
void BinaryTree<dataType>::printInPreOrder() {
    if (isEmpty()) {
        cout << "The Tree is Empty\n" ;
        return;
    }
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

//////////////////////////

template<class dataType>
int BinaryTree<dataType>::numberOfLeaves() {
    return numberOfLeavesHelper(root) ;
}

template<class dataType>
bool BinaryTree<dataType> :: isExist(dataType value) {
    return isExistHepler(root , value ) ;
}

template<class dataType>
void BinaryTree<dataType> :: clear() {
    clearHelper(root) ;
    root = nullptr ;
}

template<class dataType>
void BinaryTree<dataType>::printInLevelOrder() {
    queue<Node<dataType>*> nodes ;
    nodes.push(root) ;
    int level = 0 ;

    while(!nodes.empty()) {
        int size = nodes.size() ;

        cout << "Level " << level << " : " ;
        while(size--) {
            Node<dataType>* curr = nodes.front();
            nodes.pop();

            cout << curr->data << ' ' ;
            if (curr->left)
                nodes.push(curr->left) ;
            if (curr->right)
                nodes.push(curr->right) ;
        }
        level++ ;
        cout << '\n' ;
    }
}



