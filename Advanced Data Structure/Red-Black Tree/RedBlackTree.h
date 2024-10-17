
#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

template<class dataType>
struct Node {
    dataType data ;
    Node* left ;
    Node* right ;
    Node(dataType data ) {
        left = right = nullptr ;
        this->data = data ;
    }
};


template<class dataTyep>
class RedBlackTree {
private:
    Node<dataTyep>* root ;
public:
};



#endif //REDBLACKTREE_H
