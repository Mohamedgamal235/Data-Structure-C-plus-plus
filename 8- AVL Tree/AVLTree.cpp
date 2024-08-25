#include "AVLTree.h"
using namespace std;

// ======================================================================================================== //
// ================================== Implementation Struct Functions ===================================== //
// ======================================================================================================== //


template<class dataType>
Node<dataType>::Node(dataType data) {
    this->data = data ;
    left = nullptr ;
    right = nullptr ;
    heghit = 0 ;
}

//------------

template<class dataType>
int Node<dataType>::childHeghit(Node<dataType> *node) {
    if (!node)
        return -1 ; // for null and updateHeghit function to make it zero for leaf node
    return node->heghit ;
}

//------------

template<class dataType>
int Node<dataType>::updateHeghit() {
    heghit = 1 + max(childHeghit(left) , childHeghit(right)) ;
    return heghit ;
}

//------------

template<class dataType>
int Node<dataType>::balanceFactor() {
    return childHeghit(left) - childHeghit(right) ;
}

//------------


// ======================================================================================================== //
// ================================== Implementation Class Functions ====================================== //
// ======================================================================================================== //


// ============================================================ //
// ============== Implementation Helper Functions ============= //
// ============================================================ //

template<class dataType>
Node<dataType>* AVLTree<dataType>::leftRotation(Node<dataType> *parent) {
    Node<dataType>* child = parent->right ;
    parent->right = child->left ;
    child->left = parent ;
    parent->updateHeghit() ;
    child->updateHeghit() ;
    return child ;
}

template<class dataType>
Node<dataType>* AVLTree<dataType>::rightRotation(Node<dataType> *child ) {
    Node<dataType>* parent = child->right ;
    child->left = parent->right ;
    parent->right = child ;
    parent->updateHeghit();
    child->updateHeghit();
    return parent ;
}

template<class dataType>
Node<dataType>* AVLTree<dataType>::makeBalance(Node<dataType> *curr) {
    // i have 4 imbalance cases : R -> right , L -> left
    // RR , LL , RL , LR

    if (curr->balanceFactor() == 2) { // L
        if (curr->left->balanceFactor() == -1) // LR or not ???
            curr->left = leftRotation(curr->left) ;

        curr = rightRotation(curr) ; // balance LL
    }
    else if (curr->balanceFactor() == -2) { // R
        if (curr->right->balanceFactor() == 1 ) // RL or Not ???
            curr->right = rightRotation(curr->right) ;

        curr = leftRotation(curr) ;
    }

    return curr ;
}

template<class dataType>
Node<dataType> *AVLTree<dataType>::insertHelper(dataType value, Node<dataType> *curr) {
    if (value > curr->data) {
        if (!curr->right)
            curr->right = new Node<dataType>(value) ;
        else
            curr->right = insertHelper(value , curr->right) ;
    }
    else if (value < curr->data) {
        if (!curr->left)
            curr->left = new Node<dataType>(value) ;
        else
            curr->left = insertHelper(value , curr->left);
    }

    curr->updateHeghit();
    curr = makeBalance(curr) ;
    return curr ;
}

// ============================================================ //
// ============== Implementation user Functions =============== //
// ============================================================ //


template<class dataType>
void AVLTree<dataType>::insert(dataType value) {
    if (!root)
        root = new Node<dataType>(value) ;
    else
        root = insertHelper(value , root ) ;
}




































