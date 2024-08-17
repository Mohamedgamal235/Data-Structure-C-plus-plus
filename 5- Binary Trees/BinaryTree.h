#ifndef BINARYTREE_H
#define BINARYTREE_H

template<class T>
struct Node {
    T data ;
    Node<T>* left ;
    Node<T>* right ;
    Node(T val) {
        data = val ;
        left = right = nullptr ;
    }
};

template<class dataType>
class BinaryTree {
private:
    Node<dataType>* root ;
    void printInOrderHelper(Node<dataType>* curr) ;
public:
    BinaryTree();
    ~BinaryTree();
    void printInOrder() ;
};

#endif //BINARYTREE_H