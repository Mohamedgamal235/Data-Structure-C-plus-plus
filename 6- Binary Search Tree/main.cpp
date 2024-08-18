#include <iostream>
#include "BinarySearchTree.cpp"
using namespace std;

int main() {

    BinarySearchTree<int> tree ;

    tree.insert(50) ;
    tree.insert(20) ;
    tree.insert(15) ;
    tree.insert(70) ;
    tree.insert(73) ;
    tree.insert(60) ;
    tree.insert(45) ;
    tree.insert(35) ;

    cout << "InOrder: ";
    tree.printInOrder();
    cout << '\n' ;

    cout << "\nPostOrder: ";
    tree.printInPostOrder();
    cout << '\n' ;

    cout << "\nPreOrder: ";
    tree.printInPreOrder() ;
    cout << '\n' ;

    return 0;
}