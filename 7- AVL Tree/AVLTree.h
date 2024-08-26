#ifndef AVLTREE_H
#define AVLTREE_H

template<class dataType>
struct Node {
    int heghit ;
    dataType data ;
    Node<dataType>* left ;
    Node<dataType>* right ;
    Node(dataType data);
    int childHeghit(Node<dataType> * node) ;
    int updateHeghit();
    int balanceFactor();
};

template<class dataType>
class AVLTree {
private:
    Node<dataType>* root ;
    void inOrder(Node<dataType>* curr);
    void inPre(Node<dataType>* curr);
    void inPost(Node<dataType>* curr);
    Node<dataType>* leftRotation(Node<dataType>* P) ;
    Node<dataType>* rightRotation(Node<dataType>* Q) ;
    Node<dataType>* makeBalance(Node<dataType>* curr) ;
    Node<dataType>* insertHelper(dataType value , Node<dataType>* curr) ;
    Node<dataType>* specialDelete(Node<dataType> *curr  , Node<dataType>* child) ;
    Node<dataType>* removeHelper(Node<dataType>* curr , dataType value) ;
    dataType getMaxHelper(Node<dataType>* curr) ;
    dataType getMinHelper(Node<dataType>* curr) ;
    void clearHelper(Node<dataType>* curr) ;

public:
    AVLTree();
    ~AVLTree();
    void insert(dataType value) ;
    void remove(dataType value) ;
    dataType getMax() ;
    dataType getMin() ;
    void printInOrder() ;
    void printInPreOrder() ;
    void printInPostOrder() ;
    void clear() ;
};



#endif //AVLTREE_H
