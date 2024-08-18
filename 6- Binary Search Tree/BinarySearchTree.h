#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

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
    Node<dataType> root ;

public:
    BinarySearchTree() ;
    ~BinarySearchTree() ;

};



#endif //BINARYSEARCHTREE_H
