#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

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
    Node<dataType> root ;

    void insertHelper(Node<dataType>* curr , dataType value)

public:
    BinarySearchTree() ;
    ~BinarySearchTree() ;
    void insert(dataType value) ;
    bool isEmpty() ;
};



#endif //BINARYSEARCHTREE_H
