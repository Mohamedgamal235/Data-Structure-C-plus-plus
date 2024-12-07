#include "BTree.h"
using namespace std ;

// ========================================================================= //
// ================= Implementation Helper Functions ======================= //
// ========================================================================= //














// ========================================================================= //
// ================= Implementation User Functions ========================= //
// ========================================================================= //


template<class dataType, int ORDER>
BTree<dataType, ORDER>::BTree() {
    root = new Node<dataType , ORDER>(true) ;
}

template<class dataType, int ORDER>
BTree<dataType, ORDER>::~BTree() {
    clear();
}

template<class dataType, int ORDER>
void BTree<dataType, ORDER>::insert(dataType val) {
    if (!root) {

    }
}

template<class dataType, int ORDER>
void BTree<dataType, ORDER>::remove() {

}

template<class dataType, int ORDER>
dataType BTree<dataType, ORDER>::search(dataType val) {

}

template<class dataType, int ORDER>
void BTree<dataType, ORDER>::print() {

}

template<class dataType, int ORDER>
void BTree<dataType, ORDER>::clear() {

}
















