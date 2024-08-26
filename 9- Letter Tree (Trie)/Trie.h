#ifndef TRIE_H
#define TRIE_H

#include <iostream>
using namespace std ;

class Trie {
private:
    static const int MAX_CHAR ;
    Trie* child ;
    bool isLeaf ;

public:
    Trie();
    ~Trie() ;
    void insert(string str , int idx = 0) ;
    bool wordExist(string str , int idx = 0 ) ;
    bool prefixExist(string str , int idx = 0) ;
};



#endif //TRIE_H
