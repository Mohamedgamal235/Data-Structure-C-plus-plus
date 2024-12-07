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
    Node* curr = header ;

    vector<Node*> newHeader(maxLevel + 1 , nullptr );

    for (int i = level ; i >= 0 ; i--) {
        while (curr->forward[i] && curr->forward[i]->key < val)
            curr = curr->forward[i];
        newHeader[i] = curr ;
    }

    curr = curr->forward[0];

    if (!curr || curr->key != val) {
        int newLevel = randomLevel();

        if (newLevel > level) { // update arr
            for (int i = level + 1 ; i <= newLevel ; i++)
                newHeader[i] = header ;
            level = newLevel ;
        }

        Node* newNode = new Node(val , newLevel);

        for (int i = 0 ; i <= newLevel ; i++) {
            newNode->forward[i] = newHeader[i]->forward[i];
            newHeader[i]->forward[i] = newNode ;
        }
    }
}

void SkipList::remove(int val) {
    Node* curr = header ;
    vector<Node*> newHeader(maxLevel + 1 , nullptr);


    for (int i = level ; i >= 0 ; i--) {
        while (curr->forward[i] && curr->forward[i]->key < val)
            curr = curr->forward[i];
        newHeader[i] = curr ;
    }

    curr = curr->forward[0] ;

    if (curr && curr->key == val) {
        for (int i = 0 ; i <= level ; i++) {
            if(newHeader[i]->forward[i] != curr)
                break;
            newHeader[i]->forward[i] = curr->forward[i] ;
        }

        delete curr ;

        while (level > 0 && !header->forward[level])
            level-- ;

    }
    else
        cout <<"Key Not Found to remove!\n" ;
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
    cout << "\n***** Skip List *****\n";
    for (int i = 0; i <= level; i++) {
        Node* node = header->forward[i];
        cout << "Level " << i << ": ";
        while (node) {
            cout << node->key << " ";
            node = node->forward[i];
        }
        cout << "\n";
    }
}


void SkipList::clear() {
    Node* curr = header ;
    while (curr) {
        Node* next = curr->forward[0];
        delete curr ;
        curr = next ;
    }
    header = new Node(-1, maxLevel);
    level = 0;
}



