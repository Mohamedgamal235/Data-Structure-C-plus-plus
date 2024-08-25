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





































