#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <vector>
using namespace std;

template<class dataType>
struct Node {
    dataType data ;
    Node<dataType>* left ;
    Node<dataType>* right ;
    Node(dataType data) : data(data) , left(nullptr) , right(nullptr) {}
};

template<class dataType>
class BinarySearchTree {
private:
    Node<dataType>* root ;

    void inOrder(Node<dataType>* curr);
    void inPre(Node<dataType>* curr);
    void inPost(Node<dataType>* curr);
    void insertHelper(Node<dataType>* curr , dataType value);
    Node<dataType>* specialDelete(Node<dataType> *curr  , Node<dataType>* child) ;
    Node<dataType>* removeHelper(Node<dataType>* curr , dataType value) ;
    void clearHelper(Node<dataType>* curr) ;
    bool searchHelper(Node<dataType>* curr , dataType value ) ;
    dataType getMaxHelper(Node<dataType>* curr) ;
    dataType getMinHelper(Node<dataType>* curr) ;
    dataType successorHelper(Node<dataType>* curr , dataType value) ;
    Node<dataType>* searchForSuccessor(Node<dataType>* curr , dataType value) ;

public:
    BinarySearchTree() ;
    ~BinarySearchTree() ;
    void insert(dataType value) ;
    void remove(dataType value) ;
    bool isExist(dataType value) ;
    dataType successor(dataType value ) ;
    bool isEmpty() ;
    dataType getMax() ;
    dataType getMin() ;
    void printInOrder() ;
    void printInPreOrder() ;
    void printInPostOrder() ;
    void printLevelOrider() ;
    void clear() ;
};



#endif //BINARYSEARCHTREE_H
