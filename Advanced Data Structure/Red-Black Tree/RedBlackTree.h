
#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <iostream>
using namespace std ;

template<class dataType>
struct Node {
    dataType data ;
    Node* left ;
    Node* right ;
    Node(dataType data ) {
        left = right = nullptr ;
        this->data = data ;
    }
};


template<class dataType>
class RedBlackTree {
private:
    Node<dataType>* root;
    void inOrder(Node<dataType>* curr);
    void inPre(Node<dataType>* curr);
    void inPost(Node<dataType>* curr);
    Node<dataType>* rightRotation(Node<dataType>* child);
    Node<dataType>* leftRotation(Node<dataType>* parent) ;
    Node<dataType>* insertHelper(Node<dataType>* curr , dataType value) ;
    Node<dataType>* getMaxHelper(Node<dataType>* curr) ;
    Node<dataType>* getMinHelper(Node<dataType>* curr) ;
    void clearHelper(Node<dataType>* curr) ;

public:
    RedBlackTree();
    ~RedBlackTree();
    void printInOrder();
    void printInPreOrder();
    void printInPostOrder();
    void insert(dataType value) ;
    void clear() ;

};


#endif //REDBLACKTREE_H
