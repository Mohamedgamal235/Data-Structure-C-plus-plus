#include "Trie.h"

#include <string.h>

const int Trie::MAX_CHAR = 26 ;

//------------

Trie::Trie() {
    isLeaf = false ;
    // make set an array to zeros .
    memset(child , 0 , sizeof(child)) ;
}

//------------

Trie::~Trie() {
    delete[] child ;
}

//------------

void Trie::insert(string str, int idx) {
    if (idx == str.size()) {
        isLeaf = true ;
        return ;
    }

    int curr = str[idx] - 'a' ;
    if (child[curr] == 0)
        child[curr] = new Trie() ;
    child[curr]->insert(str , idx + 1 ) ;
}


//------------

bool Trie::wordExist(string str, int idx) {
    if (idx == str.size())
        return isLeaf ;

    int curr = str[idx] - 'a' ;
    if (child[curr] == 0)
        return false ;

    child[curr]->wordExist(str , idx+1) ; 
}























