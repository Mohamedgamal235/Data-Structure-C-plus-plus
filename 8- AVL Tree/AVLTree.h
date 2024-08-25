
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
    
    Node<dataType>* insertHelper(dataType value , Node<dataType>* curr) ;

public:
    AVLTree();
    ~AVLTree();
    void insert(dataType value) ;
};



#endif //AVLTREE_H
