#include "SkipList.h"

int SkipList::randomLevel() {
    int level = 0 ;
    while ((double) rand() / RAND_MAX < probability && level < maxLevel)
        level++ ;

    return level ;
}

SkipList::SkipList(int maxLevel, double probability) {
    this->maxLevel = maxLevel ;
    this->probability = probability ;
    level = 0 ;
    header = new Node(-1 , maxLevel);
}

SkipList::~SkipList() {
    clear();
}

void SkipList::insert(int val) {

}


void SkipList::remove(int val) {

}


bool SkipList::search(int val) {
    Node* curr = header ;
    
    for (int i = level ; i >= 0 ; i--) {
        while (curr->forward[i] && curr->forward[i]->key < val)
            curr = curr->forward[i];
    }
    curr = curr->forward[0];

    if (curr && curr->key == val)
        return true ;
    
    return false ; 
}


void SkipList::print() {

}


void SkipList::clear() {
    Node* curr = header ;
    while (curr) {
        Node* next = curr->forward[0];
        delete curr ;
        curr = next ;
    }
}



