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
    
    // ============== Extra Function for Practice if you want ============== //
    dataType maxElementHelper(Node<dataType>* curr) ;
    int heightOfTreeHelper(Node<dataType>* curr) ;
    int numberOfNodesHelper(Node<dataType>* curr) ;
    int numberOfLeavesHelper(Node<dataType>* curr) ;
    bool isExistHepler(Node<dataType>* curr , dataType value) ;
    void clearHelper(Node<dataType>* curr) ;

public: // ============== Public ============== //

    // ============== Basic Function ============== //
    BinaryTree(const dataType &val);
    ~BinaryTree();
    void printInOrder() ;
    void printInPostOrder() ;
    void printInPreOrder() ;
    void insert(const vector<dataType> &values , const vector<char> &direction ) ;
    bool isEmpty() ;

    // ============== Extra Function for Practice if you want ============== //
    dataType maxElement() ;
    int heightOfTree();
    int numberOfNodes() ;
    int numberOfLeaves() ;
    bool isExist(dataType value) ;
    void clear();

};

#endif //BINARYTREE_H
