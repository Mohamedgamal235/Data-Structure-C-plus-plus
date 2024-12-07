
#ifndef SKIPLIST_H
#define SKIPLIST_H

#include <iostream>
#include <cstring>
#include <vector>
using namespace std ;

struct Node {
    int key ;
    vector<Node*> forward ;

    Node(int key , int level) {
        this->key = key ;
        forward = vector<Node*>(level + 1 , nullptr) ;
    }
};

class SkipList {
private:
    int maxLevel ;
    double Probability  ;
    int level ;

    Node* header ;

    int randomLevel(); // make random level for nodes

public:
    SkipList(int maxLevel , double Probability );
    ~SkipList();

    void insert(int key);
    void remove(int key);
    bool search(int key);
    void print();

};



#endif //SKIPLIST_H
