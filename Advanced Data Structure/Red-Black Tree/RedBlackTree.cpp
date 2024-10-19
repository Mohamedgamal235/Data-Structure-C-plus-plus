#include "RedBlackTree.h"

// ======================================================================================================== //
// ================================== Implementation Class Functions ====================================== //
// ======================================================================================================== //

// ============================================================ //
// ============== Implementation Helper Functions ============= //
// ============================================================ //

template<class dataType>
void RedBlackTree<dataType>::inOrder(Node<dataType> *curr) {
    if (!curr)
        return;

    inOrder(curr->left);
    cout << curr->data << ' ' ;
    inOrder(curr->right);
}

//----------------------

template<class dataType>
void RedBlackTree<dataType>::inPre(Node<dataType> *curr) {
    if (!curr)
        return;
    cout << curr->data << ' ';
    inPre(curr->left);
    inPre(curr->right);
}

//----------------------

template<class dataType>
void RedBlackTree<dataType>::inPost(Node<dataType> *curr) {
    if (!curr)
        return;
    inPost(curr->left);
    inPost(curr->right);
    cout << curr->data << ' ';
}

//----------------------

template<class dataType>
Node<dataType>* RedBlackTree<dataType>::leftRotation(Node<dataType>* parent) {
    Node<dataType>* child = parent->right;
    parent->right = child->left;
    if (child->left) child->left->parent = parent;
    child->parent = parent->parent;
    child->left = parent;
    parent->parent = child;

    if (child->parent) {
        if (child->parent->left == parent) {
            child->parent->left = child;
        } else {
            child->parent->right = child;
        }
    }
    return child;
}

//----------------------

template<class dataType>
Node<dataType>* RedBlackTree<dataType>::rightRotation(Node<dataType>* child) {
    Node<dataType>* parent = child->left;
    child->left = parent->right;
    if (parent->right) parent->right->parent = child;
    parent->parent = child->parent;
    parent->right = child;
    child->parent = parent;

    if (parent->parent) {
        if (parent->parent->left == child) {
            parent->parent->left = parent;
        } else {
            parent->parent->right = parent;
        }
    }
    return parent;
}

//----------------------

template<class dataType>
void RedBlackTree<dataType>::fixInsertion(Node<dataType> *curr) {
    // Base case: if the node is root, recolor it black.
    if (curr == root) {
        curr->color = "BLACK";
        return;
    }

    // If the parent is black, no fix is needed.
    if (curr->parent->color == "BLACK")
        return;

    // Parent is red, so a violation exists.
    Node<dataType>* parent = curr->parent;
    Node<dataType>* grandParent = parent->parent;
    Node<dataType>* uncle = (grandParent->left == parent) ? grandParent->right : grandParent->left;

    // Case 1: Uncle is RED -> Recoloring
    if (uncle && uncle->color == "RED") {
        parent->color = "BLACK";
        uncle->color = "BLACK";
        grandParent->color = "RED";
        fixInsertion(grandParent); // Recur on grandparent to fix the violation upwards
    } else {
        // Case 2 and 3: Uncle is BLACK or NULL -> Rotations & Recolor
        if (parent == grandParent->left) {
            if (curr == parent->right) {
                // Left-Right case
                parent = leftRotation(parent);
            }
            // Left-Left case
            grandParent = rightRotation(grandParent);
            grandParent->color = "RED";
            parent->color = "BLACK";
        } else {
            if (curr == parent->left) {
                // Right-Left case
                parent = rightRotation(parent);
            }
            // Right-Right case
            grandParent = leftRotation(grandParent);
            parent->color = "BLACK";
            grandParent->color = "RED";
        }

        if (grandParent == root)
            root = grandParent;

        root->color = "BLACK"; // Ensure root is always black
    }
}

//----------------------

template<class dataType>
Node<dataType>* RedBlackTree<dataType>::insertHelper(Node<dataType> *curr, dataType value) {
    if (!curr)
        return new Node<dataType>(value);

    if (value > curr->data)
        curr->right = insertHelper(curr->right, value);
    else if (value < curr->data)
        curr->left = insertHelper(curr->left, value);
    else
        return curr; // exist

    return curr; // Return current node to maintain the tree structure
}

//----------------------

template<class dataType>
Node<dataType>* RedBlackTree<dataType>::getMaxHelper(Node<dataType>* curr) {
    if (!curr->right)
        return curr;

    return getMaxHelper(curr->right);
}

//----------------------

template<class dataType>
Node<dataType>* RedBlackTree<dataType>::getMinHelper(Node<dataType>* curr) {
    if (!curr->left)
        return curr;

    return getMinHelper(curr->left);
}

//----------------------

template<class dataType>
void RedBlackTree<dataType>::clearHelper(Node<dataType> *curr) {
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
RedBlackTree<dataType>::RedBlackTree() {
    root = nullptr;
}

//----------------------

template<class dataType>
RedBlackTree<dataType>::~RedBlackTree() {
    clear();
}

//----------------------

template<class dataType>
void RedBlackTree<dataType>::insert(dataType value) {
    Node<dataType>* newNode = insertHelper(root, value);
    if (!root) {
        root = newNode;
        root->color = "BLACK"; // New root must be black
    }
    fixInsertion(newNode); // Fix violations after insertion
}

//----------------------

template<class dataType>
void RedBlackTree<dataType>::clear() {
    if (!root) {
        cout << "Tree is already empty.\n";
        return;
    }
    clearHelper(root);
    root = nullptr;
}

//----------------------

template<class dataType>
void RedBlackTree<dataType>::printInOrder() {
    inOrder(root) ;
}

//----------------------

template<class dataType>
void RedBlackTree<dataType>::printInPreOrder() {
    inPre(root) ;
}


//----------------------

template<class dataType>
void RedBlackTree<dataType>::printInPostOrder() {
    inPost(root) ;
}

