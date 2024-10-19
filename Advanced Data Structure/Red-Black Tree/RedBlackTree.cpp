#include "RedBlackTree.h"

// ======================================================================================================== //
// ================================== Implementation Class Functions ====================================== //
// ======================================================================================================== //

// ============================================================ //
// ============== Implementation Helper Functions ============= //
// ============================================================ //

template<class dataType>
void RedBlackTree<dataType>::inOrder(Node<dataType>* curr) {
    if (!curr)
        return;

    inOrder(curr->left);
    cout << curr->data << ' ';
    inOrder(curr->right);
}

//----------------------

template<class dataType>
void RedBlackTree<dataType>::inPre(Node<dataType>* curr) {
    if (!curr)
        return;
    cout << curr->data << ' ';
    inPre(curr->left);
    inPre(curr->right);
}

//----------------------

template<class dataType>
void RedBlackTree<dataType>::inPost(Node<dataType>* curr) {
    if (!curr)
        return;
    inPost(curr->left);
    inPost(curr->right);
    cout << curr->data << ' ';
}

//----------------------

template <class dataType>
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
    } else {
        root = child; // Update root if necessary
    }

    return child;
}

//----------------------

template <class dataType>
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
    } else {
        root = parent;
    }

    return parent;
}

//----------------------

template<class dataType>
Node<dataType>* RedBlackTree<dataType>::insertHelper(Node<dataType>* curr, dataType value) {
    if (!curr) {
        return new Node<dataType>(value);
    }

    if (value < curr->data) {
        curr->left = insertHelper(curr->left, value);
        curr->left->parent = curr; // Set parent pointer
    } else if (value > curr->data) {
        curr->right = insertHelper(curr->right, value);
        curr->right->parent = curr; // Set parent pointer
    }

    return curr; // Return current node to maintain the tree structure
}

//----------------------

template<class dataType>
void RedBlackTree<dataType>::fixInsertion(Node<dataType>* curr) {
    while (curr != root && curr->parent->color == "RED") {
        Node<dataType>* parent = curr->parent;
        Node<dataType>* grandParent = parent->parent;
        Node<dataType>* uncle = (grandParent->left == parent) ? grandParent->right : grandParent->left;

        if (uncle && uncle->color == "RED") {
            // Case 1: Uncle is RED
            parent->color = "BLACK";
            uncle->color = "BLACK";
            grandParent->color = "RED";
            curr = grandParent; // Move up the tree
        } else {
            // Case 2: Uncle is BLACK
            if (parent == grandParent->left) {
                if (curr == parent->right) {
                    // Left-Right case
                    leftRotation(parent);
                    curr = parent;
                    parent = curr->parent;
                }
                // Left-Left case
                rightRotation(grandParent);
                swap(parent->color, grandParent->color);
            } else {
                if (curr == parent->left) {
                    // Right-Left case
                    rightRotation(parent);
                    curr = parent;
                    parent = curr->parent;
                }
                // Right-Right case
                leftRotation(grandParent);
                swap(parent->color, grandParent->color);
            }
        }
    }
    root->color = "BLACK"; // Ensure root is always black
}

//----------------------

template<class dataType>
Node<dataType>* RedBlackTree<dataType>::specialDelete(Node<dataType>* curr, Node<dataType>* child) {
    curr->data = child->data;
    curr->left = child->left;
    curr->right = child->right;
    delete child;
    return curr;
}

//----------------------

template<class dataType>
Node<dataType>* RedBlackTree<dataType>::removeHelper(Node<dataType>* curr, dataType value) {
    if (!curr)
        return nullptr;

    if (value > curr->data)
        curr = removeHelper(curr->right, value);
    else if (value < curr->data)
        curr = removeHelper(curr->left, value);
    else {
        // Case 1: Node with no children (leaf node)
        if (!curr->left && !curr->right) {
            delete curr;
            return nullptr;
        }

        // Case 2: Node with only one child
        if (!curr->left)
            return specialDelete(curr, curr->right);

        if (!curr->right)
            return specialDelete(curr, curr->left);

        // Case 3: Node with two children
        curr->data = getMaxHelper(curr->left)->data; // Copy predecessor value
        curr->left = removeHelper(curr->left, curr->data);
    }
    return curr; // Return current node to maintain the tree structure
}

//----------------------

template <class dataType>
void RedBlackTree<dataType>::fixDeletion(Node<dataType>* curr) {
    while (curr != root && curr->color == "BLACK") {
        if (curr == curr->parent->left) {
            Node<dataType>* sibling = curr->parent->right;

            if (sibling->color == "RED") {
                sibling->color = "BLACK";
                curr->parent->color = "RED";
                leftRotation(curr->parent);
                sibling = curr->parent->right; // Update sibling
            }

            if ((!sibling->left || sibling->left->color == "BLACK") &&
                (!sibling->right || sibling->right->color == "BLACK")) {
                if (sibling->left) sibling->left->color = "BLACK";
                if (sibling->right) sibling->right->color = "BLACK";
                sibling->color = "RED";
                curr = curr->parent; // Move up the tree
            } else {
                if (!sibling->right || sibling->right->color == "BLACK") {
                    if (sibling->left) sibling->left->color = "BLACK";
                    sibling->color = "RED";
                    rightRotation(sibling);
                    sibling = curr->parent->right; // Update sibling
                }
                sibling->color = curr->parent->color;
                curr->parent->color = "BLACK";
                if (sibling->right) sibling->right->color = "BLACK";
                leftRotation(curr->parent);
                curr = root; // Terminate loop
            }
        } else {
            Node<dataType>* sibling = curr->parent->left;

            if (sibling->color == "RED") {
                sibling->color = "BLACK";
                curr->parent->color = "RED";
                rightRotation(curr->parent);
                sibling = curr->parent->left; // Update sibling
            }

            if ((!sibling->right || sibling->right->color == "BLACK") &&
                (!sibling->left || sibling->left->color == "BLACK")) {
                if (sibling->left) sibling->left->color = "BLACK";
                if (sibling->right) sibling->right->color = "BLACK";
                sibling->color = "RED";
                curr = curr->parent; // Move up the tree
            } else {
                if (!sibling->left || sibling->left->color == "BLACK") {
                    if (sibling->right) sibling->right->color = "BLACK";
                    sibling->color = "RED";
                    leftRotation(sibling);
                    sibling = curr->parent->left; // Update sibling
                }
                sibling->color = curr->parent->color;
                curr->parent->color = "BLACK";
                if (sibling->left) sibling->left->color = "BLACK";
                rightRotation(curr->parent);
                curr = root; // Terminate loop
            }
        }
    }
    curr->color = "BLACK"; // Ensure root is always black
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
void RedBlackTree<dataType>::clearHelper(Node<dataType>* curr) {
    if (!curr)
        return;

    clearHelper(curr->left);
    clearHelper(curr->right);
    delete curr;
}

// ============================================================ //
// ============== Implementation user Functions =============== //
// ============================================================ //

template <class dataType>
RedBlackTree<dataType>::RedBlackTree() : root(nullptr) {}

// Destructor
template <class dataType>
RedBlackTree<dataType>::~RedBlackTree() {
    clear();
}

// Clear the tree
template <class dataType>
void RedBlackTree<dataType>::clear() {
    clearHelper(root);
    root = nullptr;
}

// Insert a value
template <class dataType>
void RedBlackTree<dataType>::insert(dataType value) {
    Node<dataType>* newNode = insertHelper(root, value);
    if (!root) {
        root = newNode;
        root->color = "BLACK"; // New root must be black
    } else {
        fixInsertion(newNode); // Fix violations after insertion
    }
}

// Remove a value
template <class dataType>
void RedBlackTree<dataType>::remove(dataType value) {
    if (!root) {
        cout << "Tree is already empty.\n";
        return;
    }
    Node<dataType>* nodeToRemove = removeHelper(root, value);
    if (nodeToRemove) {
        fixDeletion(nodeToRemove);
    }
}

// Print in-order traversal
template <class dataType>
void RedBlackTree<dataType>::printInOrder() {
    inOrder(root);
}

// Print pre-order traversal
template <class dataType>
void RedBlackTree<dataType>::printInPreOrder() {
    inPre(root);
}

// Print post-order traversal
template <class dataType>
void RedBlackTree<dataType>::printInPostOrder() {
    inPost(root);
}