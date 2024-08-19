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
    Node<dataType>* root ;

    void inOrder(Node<dataType>* curr);
    void inPre(Node<dataType>* curr);
    void inPost(Node<dataType>* curr);
    void insertHelper(Node<dataType>* curr , dataType value);
    Node<dataType>* removeHelper(Node<dataType>* curr , dataType value) ;
    void clearHelper(Node<dataType>* curr) ;
    bool searchHelper(Node<dataType>* curr , dataType value ) ;
    dataType getMaxHelper(Node<dataType>* curr) ;
    dataType getMinHelper(Node<dataType>* curr) ;

public:
    BinarySearchTree() ;
    ~BinarySearchTree() ;
    void insert(dataType value) ;
    void remove(dataType value) ;
    bool isEmpty() ;
    bool isExist(dataType value) ;
    dataType getMax() ;
    dataType getMin() ;
    void printInOrder() ;
    void printInPreOrder() ;
    void printInPostOrder() ;
    void printLevelOrider() ;
    void clear() ;
};



#endif //BINARYSEARCHTREE_H
