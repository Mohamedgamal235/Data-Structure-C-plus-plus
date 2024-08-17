#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <vector>
using namespace std;

template<class T>
struct Node {
    T data ;
    Node<T>* left ;
    Node<T>* right ;
    Node(T val) : data(val) , left(nullptr) , right(nullptr) {}
};

template<class dataType>
class BinaryTree {
private:
    Node<dataType>* root ;
    void printInOrderHelper(Node<dataType>* curr) ;
    void printInPostOrderHelper(Node<dataType>* curr) ;
    void printInPreOrderHelper(Node<dataType>* curr) ;
public:
    BinaryTree(const dataType &val);
    ~BinaryTree();
    void printInOrder() ;
    void printInPostOrder() ;
    void printInPreOrder() ;
    void insert(const vector<dataType> &values , const vector<char> &direction ) ;
};

#endif //BINARYTREE_H
