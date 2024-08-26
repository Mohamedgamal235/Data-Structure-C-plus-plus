#include "Trie.h"

Trie::Trie() {
    isLeaf = false;
    memset(child, 0, sizeof(child));
}

//-----------------

Trie::~Trie() {
    for (int i = 0; i < MAX_CHAR; i++) {
        if (child[i] != nullptr) {
            delete child[i];
        }
    }
}

//-----------------

void Trie::insert(string str, int idx) {
    if (idx == str.size()) {
        isLeaf = true;
        return;
    }

    int curr = str[idx] - 'a';
    if (child[curr] == nullptr)
        child[curr] = new Trie();

    child[curr]->insert(str, idx + 1);
}

//-----------------

bool Trie::wordExist(string str, int idx) {
    if (idx == str.size())
        return isLeaf;

    int curr = str[idx] - 'a';
    if (child[curr] == nullptr)
        return false;

    return child[curr]->wordExist(str, idx + 1);
}

//-----------------

bool Trie::prefixExist(string str, int idx) {
    if (idx == str.size())
        return true;

    int curr = str[idx] - 'a';
    if (child[curr] == nullptr)
        return false;

    return child[curr]->prefixExist(str, idx + 1);
}

