#ifndef BTREE_H
#define BTREE_H
#include <bits/range_access.h>

template<class dataType , int ORDER>
struct Node {
    dataType keys[ORDER - 1] ;
    Node * children ;
    int numOfKeys ;
    bool isLeaf ;
    Node(bool isLeaf) {
        numOfKeys = 0 ;
        this.isLeaf = isLeaf ;
        this->children = new dataType [ORDER];
        for (int i = 0 ; i < ORDER ; i++)
            children[i] = nullptr ;
    }

};

template<class dataType , int ORDER>
class BTree {
private:

    Node<dataType , ORDER>* root ;
    void insertHelper(Node<dataType , ORDER> * curr , dataType val);
    void removeHelper(Node<dataType , ORDER> * curr );
    Node<dataType , ORDER>* searchHelper(Node<dataType , ORDER> * curr , dataType val);
    dataType successorHelper(Node<dataType , ORDER>* curr , int i);
    void splitChild(Node<dataType , ORDER> * curr, int i) ;
    void clearHelper(Node<dataType , ORDER> * curr);



public:

    BTree();
    ~BTree();
    void insert(dataType val) ;
    dataType search(dataType val) ;
    void remove();
    void print();
    void clear();
    bool isEmpty();
    bool isFull();

};

#endif //BTREE_H
