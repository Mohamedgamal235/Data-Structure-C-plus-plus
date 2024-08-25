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
    Node<dataType>* leftRotation(Node<dataType>* P) ;
    Node<dataType>* rightRotation(Node<dataType>* Q) ;
    Node<dataType>* makeBalance(Node<dataType>* curr) ;
    Node<dataType>* insertHelper(dataType value , Node<dataType>* curr) ;
    void clearHelper(Node<dataType>* curr) ;

public:
    AVLTree();
    ~AVLTree();
    void insert(dataType value) ;
    void clear() ;
};



#endif //AVLTREE_H
