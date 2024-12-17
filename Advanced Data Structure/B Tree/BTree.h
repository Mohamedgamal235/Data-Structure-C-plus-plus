//
// Created by Mohamed Gamal on 18/12/2024.
//

#ifndef BTREE_H
#define BTREE_H




template<class dataType , int ORDER>
struct Node{
    int numOfKeys;
    int pos = -1;
    dataType* keys;
    Node** children;

    Node ();
    bool insertHelper (dataType value);
    Node* split (Node* node, dataType* mid);
    ~Node ();
};

template<class dataType , int ORDER>
class BTree{
private:
    Node<dataType , ORDER> *root;
    void printHelper(Node<dataType, ORDER>* curr, int space);

public:
    BTree ();
    ~BTree ();
    void insert (dataType value);
    void print() ;
};





#endif //BTREE_H
