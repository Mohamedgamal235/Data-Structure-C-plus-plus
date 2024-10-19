
#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <iostream>
using namespace std ;

template<class dataType>
struct Node {
    dataType data ;
    Node<dataType>* left ;
    Node<dataType>* right ;
    Node<dataType>* parent ;
    string color ;
    Node(dataType data ) {
        left = right = nullptr ;
        this->data = data ;
        color = "RED" ;
    }
};


template<class dataType>
class RedBlackTree {
private:
    Node<dataType>* root;
    bool RL , LR , RR , LL ;

    // Helper functions
    Node<dataType>* insertHelper(Node<dataType>* curr, dataType value);
    Node<dataType>* removeHelper(Node<dataType>* curr, dataType value);
    Node<dataType>* getMaxHelper(Node<dataType>* curr);
    Node<dataType>* getMinHelper(Node<dataType>* curr);
    Node<dataType>* specialDelete(Node<dataType>* curr , Node<dataType>* child) ;
    void clearHelper(Node<dataType>* curr);

    // Rotations
    Node<dataType>* leftRotation(Node<dataType>* curr);
    Node<dataType>* rightRotation(Node<dataType>* curr);

    // Fix functions
    void fixInsertion(Node<dataType>* newNode) ;
    void fixDeletion(Node<dataType>* curr) ;

    // Traversal functions
    void inOrder(Node<dataType>* curr);
    void inPre(Node<dataType>* curr);
    void inPost(Node<dataType>* curr);


public:
    // Constructor and destructor
    RedBlackTree();
    ~RedBlackTree();

    // Public functions
    void insert(dataType value) ;
    void remove(dataType value) ;
    void clear();
    void printInOrder();
    void printInPreOrder();
    void printInPostOrder();

};


#endif //REDBLACKTREE_H
