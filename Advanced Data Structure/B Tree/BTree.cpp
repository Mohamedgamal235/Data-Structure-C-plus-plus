#include "BTree.h"
using namespace std ;

// ========================================================================= //
// ================= Implementation Helper Functions ======================= //
// ========================================================================= //


template<class dataType, int ORDER>
void BTree<dataType, ORDER>::insertHelper(Node<dataType, ORDER> *curr, dataType val) {
    int i = curr->numOfKeys - 1 ;

    if (curr->isLeaf) {
        while (i >= 0 && val < curr->keys[i]) { // make shifts
            curr->keys[i+1] = curr->keys[i];
            i-- ;
        }
        curr->keys[i+1] = val ;
        curr->numOfKeys++ ;
    }
    else {
        while (i >=0 && val < curr->keys[i])
            i-- ;
        i++ ; // to make it at index of i + 1 to insert value okay

        if (curr->children[i].numOfKeys == ORDER - 1) {
            splitChild(curr , i);


            if (val > curr->keys[i])
                i++ ;

        }
        insertHelper(curr->children[i] , val);
    }
}

template<class dataType, int ORDER>
void BTree<dataType, ORDER>::splitChild(Node<dataType, ORDER> *parent, int idx) {
    Node<dataType , ORDER>* fullChild = parent->children[idx] ;
    Node<dataType , ORDER>* newChild = new Node<dataType , ORDER>(fullChild->isLeaf); // to make it on same level

    newChild->numOfKeys = ORDER / 2 - 1 ;

    for (int j = 0 ; j < ORDER / 2 - 1 ; j++)
        newChild->keys[j] = fullChild->keys[j+ORDER/2];

    if (!fullChild->isLeaf) {
        for (int j = 0 ; j < ORDER / 2 ; j++)
            newChild->children[j] = fullChild->children[j + ORDER / 2] ;
    }

    fullChild->numOfKeys = ORDER / 2 - 1 ;

    for (int j = parent->numOfKeys ; j >= idx + 1 ; j--)
        parent->children[j+1] = parent->children[j] ;

    parent->children[idx + 1] = newChild ;

    for (int i = parent->numOfKeys - 1 ; i >= idx ; i--)
        parent->keys[i+1] = parent->keys[i] ;


    parent->keys[idx] = fullChild->keys[ORDER / 2 - 1] ;
    parent->numOfKeys++ ;
}


template<class dataType, int ORDER>
Node<dataType, ORDER> *BTree<dataType, ORDER>::searchHelper(Node<dataType, ORDER> *curr, dataType val) {
    int idx = 0 ;
    while (idx < curr->numOfKeys && val > curr->keys[idx])
        idx++ ;

    if (idx < curr->numOfKeys && val == curr->keys[idx])
        return curr ;

    if (curr->isLeaf)
        return nullptr ;

    return searchHelper(curr->children[idx] , val) ;
}

template<class dataType, int ORDER>
dataType BTree<dataType, ORDER>::getSuccessor(Node<dataType, ORDER> *node, int i) {
    Node<dataType , ORDER>* curr = node->children[i + 1] ;
    while (!curr->isLeaf)
        curr = curr->children[0];
    return curr->keys[0];
}

template<class dataType, int ORDER>
dataType BTree<dataType, ORDER>::getPredecessor(Node<dataType, ORDER> *node, int i) {
    Node<dataType , ORDER>* curr = node->children[i] ;
    while (!curr->isLeaf)
        curr = curr->children[curr->numOfKeys];
    return curr->keys[curr->numOfKeys-1];
}



// ========================================================================= //
// ================= Implementation User Functions ========================= //
// ========================================================================= //


template<class dataType, int ORDER>
BTree<dataType, ORDER>::BTree() {
    root = nullptr;
}

template<class dataType, int ORDER>
BTree<dataType, ORDER>::~BTree() {
    clear();
}

template<class dataType, int ORDER>
void BTree<dataType, ORDER>::insert(dataType val) {
    if (root->numOfKeys == ORDER - 1) {
        Node<dataType , ORDER>* newRoot = new Node<dataType, ORDER>(false) ;
        newRoot->children[0] = root ;
        splitChild(newRoot , 0) ;
        root = newRoot ;
        insertHelper(root , val);
    }
    else
        insertHelper(root , val);
}

template<class dataType, int ORDER>
void BTree<dataType, ORDER>::remove() {

}

template<class dataType, int ORDER>
dataType BTree<dataType, ORDER>::search(dataType val) {
    if(!root)
        return dataType();

    Node<dataType , ORDER>* res = searchHelper(root , val);
    if(res == nullptr)
        return dataType();

    return val ;
}

template<class dataType, int ORDER>
void BTree<dataType, ORDER>::print() {

}

template<class dataType, int ORDER>
void BTree<dataType, ORDER>::clear() {

}
















