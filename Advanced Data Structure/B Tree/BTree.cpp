#include "../BTree/BTree.h"
#include <iostream>
using namespace std ;

//Node implementation
template<class dataType , int ORDER>
Node<dataType , ORDER>::Node (){
    numOfKeys = 0;
    keys = new dataType[ORDER];
    children = new Node*[ORDER+1];
    for (int i = 0; i <= ORDER; ++i)
        children[i] = nullptr;
}


template<class dataType , int ORDER>
bool Node<dataType , ORDER>::insertHelper(dataType value){
    if (children[0] == nullptr){
        pos++ ;
        numOfKeys++;
        keys[pos] = value;
        for(int i = pos ; i > 0 ; i--)
            if (keys[i] < keys[i-1])
                swap(keys[i-1],keys[i]);
    }
    else{ // add to proper child heeerrreeeee
        int i = 0 ;
        while (i < numOfKeys && value > keys[i])
            i++ ;

        bool needSplit = children[i]->insertHelper(value);
        if(needSplit){
            dataType mid;
            int childIndex = i; // child
            Node<dataType , ORDER> *newNode = split(children[i], &mid);
            for(; i < numOfKeys && mid > keys[i];)
                i++;

            for (int j = numOfKeys; j > i ; j--)
                keys[j] = keys[j - 1];
            keys[i] = mid;
            ++numOfKeys;
            ++pos;

            int k;
            for (k = numOfKeys; k > childIndex + 1; k--)
                children[k] = children[k - 1];
            children[k] = newNode;
        }

    }
    if(numOfKeys == ORDER)
        return true ;

    return false ;
}


template<class dataType , int ORDER>
Node<dataType , ORDER>* Node<dataType , ORDER>::split(Node *node, dataType *mid) {
    int NumberOfKeys = node->numOfKeys;
    Node<dataType , ORDER> *newNode = new Node<dataType , ORDER>;
    int midIndex = NumberOfKeys / 2;
    *mid = node->keys[midIndex];
    int i;

    // after half ya ragel
    for (i = midIndex + 1; i < NumberOfKeys; ++i){
        newNode->pos = newNode->pos + 1 ; // be 0
        newNode->keys[newNode->pos] = node->keys[i];
        newNode->children[newNode->pos] = node->children[i];
        newNode->numOfKeys = newNode->numOfKeys + 1 ;
        node->pos = node->pos - 1 ;
        node->numOfKeys = node->numOfKeys - 1 ;
        node->children[i] = nullptr;
    }
    newNode->children[newNode->pos + 1] = node->children[i];
    node->children[i] = nullptr; // after increment i

    node->numOfKeys = node->numOfKeys - 1 ; //because we take mid-value...
    node->pos = node->pos - 1 ;
    return newNode;
}

template<class dataType , int ORDER>
Node<dataType , ORDER>::~Node (){
    for (int i = 0; i <= numOfKeys; ++i)
        delete children[i];
    delete[] children;
    delete[]keys;
}



template<class dataType , int ORDER>
BTree<dataType , ORDER>::BTree(){
    root  = nullptr;
}

template<class dataType , int ORDER>
void BTree<dataType , ORDER>::insert(dataType value){
    if (root == nullptr){
        root = new Node<dataType , ORDER>;
        root->pos++ ;
        root->keys[root->pos] = value;
        root->numOfKeys = 1;
    }
    else {
        bool needSplit = root->insertHelper(value);
        if(needSplit){
            dataType mid;
            Node<dataType , ORDER> *splitNode = root->split(root, &mid);
            Node<dataType , ORDER> *newRoot = new Node<dataType , ORDER>;
            newRoot->pos++ ; // to be 0
            newRoot->keys[newRoot->pos] = mid;
            newRoot->numOfKeys=1;
            newRoot->children[0] = root;
            newRoot->children[1] = splitNode;
            root = newRoot;
        }
    }
}


template<class dataType, int ORDER>
void BTree<dataType, ORDER>::printHelper(Node<dataType, ORDER>* curr, int space) {
    if (curr == nullptr)
        return;

    for (int i = 0; i < space; ++i)
        cout << "  ";

    for (int i = 0; i < curr->numOfKeys; ++i) {
        cout << curr->keys[i];
        if (i < curr->numOfKeys - 1)
            cout << ",";
    }
    cout << endl;

    for (int i = 0; i <= curr->numOfKeys; ++i) {
        if (curr->children[i] != nullptr)
            printHelper(curr->children[i], space + 1);
    }
}


template<class dataType, int ORDER>
void BTree<dataType, ORDER>::print() {
    printHelper(root, 0);
}


template <class dataType,int ORDER>
BTree<dataType , ORDER>::~BTree (){
    delete root;
}