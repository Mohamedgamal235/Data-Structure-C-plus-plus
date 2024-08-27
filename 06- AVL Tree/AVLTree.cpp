#include "AVLTree.h"
#include <iostream>
using namespace std;

// ======================================================================================================== //
// ================================== Implementation Struct Functions ===================================== //
// ======================================================================================================== //

template<class dataType>
Node<dataType>::Node(dataType data) {
    this->data = data;
    left = nullptr;
    right = nullptr;
    height = 0; // Fixed typo: changed "heghit" to "height"
}

//------------

template<class dataType>
int Node<dataType>::childHeight(Node<dataType> *node) {
    if (!node)
        return -1; // for null and updateHeight function to make it zero for leaf node
    return node->height;
}

//------------

template<class dataType>
int Node<dataType>::updateHeight() {
    height = 1 + max(childHeight(left), childHeight(right)); // Fixed typo: changed "childHeghit" to "childHeight"
    return height;  // Fixed typo: changed "heghit" to "height"
}

//------------

template<class dataType>
int Node<dataType>::balanceFactor() {
    return childHeight(left) - childHeight(right); // Fixed typo: changed "childHeghit" to "childHeight"
}

//------------

// ======================================================================================================== //
// ================================== Implementation Class Functions ====================================== //
// ======================================================================================================== //

// ============================================================ //
// ============== Implementation Helper Functions ============= //
// ============================================================ //

template<class dataType>
void AVLTree<dataType>::inOrder(Node<dataType>* curr) {
    if (!curr)
        return;
    inOrder(curr->left);
    cout << curr->data << ' ';
    inOrder(curr->right);
}

//----------------------

template<class dataType>
void AVLTree<dataType>::inPre(Node<dataType> *curr) {
    if (!curr)
        return;
    cout << curr->data << ' ';
    inPre(curr->left);
    inPre(curr->right);
}

//----------------------

template<class dataType>
void AVLTree<dataType>::inPost(Node<dataType> *curr) {
    if (!curr)
        return;
    inPost(curr->left);
    inPost(curr->right);
    cout << curr->data << ' ';
}

//----------------------

template<class dataType>
Node<dataType>* AVLTree<dataType>::leftRotation(Node<dataType> *parent) {
    Node<dataType>* child = parent->right;
    parent->right = child->left;
    child->left = parent;
    parent->updateHeight();
    child->updateHeight();
    return child;
}

//----------------------

template<class dataType>
Node<dataType>* AVLTree<dataType>::rightRotation(Node<dataType> *child) {
    Node<dataType>* parent = child->left;
    child->left = parent->right;
    parent->right = child;
    parent->updateHeight();
    child->updateHeight();
    return parent;
}

//----------------------

template<class dataType>
Node<dataType>* AVLTree<dataType>::makeBalance(Node<dataType> *curr) {
    // i have 4 imbalance cases : R -> right , L -> left
    // RR , LL , RL , LR

    if (curr->balanceFactor() == 2) { // L
        if (curr->left->balanceFactor() == -1) // LR or not ???
            curr->left = leftRotation(curr->left) ;

        curr = rightRotation(curr) ; // balance LL
    }
    else if (curr->balanceFactor() == -2) { // R
        if (curr->right->balanceFactor() == 1 ) // RL or Not ???
            curr->right = rightRotation(curr->right) ;

        curr = leftRotation(curr) ;
    }

    return curr ;
}


//----------------------

template<class dataType>
Node<dataType>* AVLTree<dataType>::insertHelper(dataType value, Node<dataType>* curr) {
    if (!curr) // Added missing base case for insertion
        return new Node<dataType>(value);

    if (value > curr->data) {
        curr->right = insertHelper(value, curr->right);
    } else if (value < curr->data) {
        curr->left = insertHelper(value, curr->left);
    }

    curr->updateHeight();
    curr = makeBalance(curr);
    return curr;
}

//----------------------

template<class dataType>
Node<dataType>* AVLTree<dataType>::specialDelete(Node<dataType> *curr, Node<dataType>* child) {
    // Instead of deleting the node and returning its child, copy the child's data to the current node
    // and then delete the child node. This prevents runtime errors when the node to be deleted is
    // actually the root node or any other node that should not be deleted directly.
    curr->data = child->data;
    curr->left = child->left;
    curr->right = child->right;
    delete child;
    return curr;
}

//----------------------

template<class dataType>
Node<dataType>* AVLTree<dataType>::removeHelper(Node<dataType>* curr, dataType value) {
    if (!curr)
        return nullptr;

    if (value < curr->data) {
        curr->left = removeHelper(curr->left, value);
    } else if (value > curr->data) {
        curr->right = removeHelper(curr->right, value);
    } else {
        // Case 1: Node with no children (leaf node)
        if (!curr->left && !curr->right) {
            delete curr;
            return nullptr;
        }

        // Case 2: Node with only one child
        if (!curr->left)
            return specialDelete(curr , curr->right);

        if (!curr->right)
            return specialDelete(curr , curr->left);

        // Case 3: Node with two children
        curr->data = getMaxHelper(curr->left);
        curr->left = removeHelper(curr->left, curr->data);
    }

    curr->updateHeight();
    return makeBalance(curr);
}

//----------------------

template<class dataType>
dataType AVLTree<dataType>::getMaxHelper(Node<dataType>* curr) {
    if (!curr->right)
        return curr->data;

    return getMaxHelper(curr->right);
}

//----------------------

template<class dataType>
dataType AVLTree<dataType>::getMinHelper(Node<dataType>* curr) {
    if (!curr->left)
        return curr->data;

    return getMinHelper(curr->left);
}

//----------------------

template<class dataType>
void AVLTree<dataType>::clearHelper(Node<dataType>* curr) {
    if (!curr)
        return;

    clearHelper(curr->left);
    clearHelper(curr->right);
    delete curr;
}

// ============================================================ //
// ============== Implementation user Functions =============== //
// ============================================================ //

template<class dataType>
AVLTree<dataType>::AVLTree() {
    root = nullptr;
}

template<class dataType>
AVLTree<dataType>::~AVLTree() {
    clear();
}

template<class dataType>
void AVLTree<dataType>::insert(dataType value) {
    root = insertHelper(value, root);
}

template<class dataType>
void AVLTree<dataType>::remove(dataType value) {
    if (!root) {
        cout << "Tree is empty, can't remove.\n";
        return;
    }
    root = removeHelper(root, value);
}

template<class dataType>
dataType AVLTree<dataType>::getMax() {
    if (!root) {
        throw runtime_error("Tree is empty");
    }
    return getMaxHelper(root);
}

template<class dataType>
dataType AVLTree<dataType>::getMin() {
    if (!root) {
        throw runtime_error("Tree is empty");
    }
    return getMinHelper(root);
}

template<class dataType>
void AVLTree<dataType>::printInOrder() {
    if (!root) {
        cout << "Tree is empty.\n";
        return;
    }
    inOrder(root);
    cout << endl;
}

template<class dataType>
void AVLTree<dataType>::printInPreOrder() {
    if (!root) {
        cout << "Tree is empty.\n";
        return;
    }
    inPre(root);
    cout << endl;
}

template<class dataType>
void AVLTree<dataType>::printInPostOrder() {
    if (!root) {
        cout << "Tree is empty.\n";
        return;
    }
    inPost(root);
    cout << endl;
}

template<class dataType>
void AVLTree<dataType>::clear() {
    if (!root) {
        cout << "Tree is already empty.\n";
        return;
    }
    clearHelper(root);
    root = nullptr;
}

