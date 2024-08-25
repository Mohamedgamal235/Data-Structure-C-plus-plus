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




































