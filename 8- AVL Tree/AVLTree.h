
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
    int updateChild();
    int balanceFactor();
};

template<class dataType>
class AVLTree {
private:
    Node<dataType>* root ;
public:
    AVLTree();
    ~AVLTree();
};



#endif //AVLTREE_H
