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
    cout << "\n================\n" ;

    cout << "PostOrder: ";
    tree.printInPostOrder();
    cout << "\n================\n" ;

    cout << "PreOrder: ";
    tree.printInPreOrder();
    cout << "\n================\n" ;

    cout << "isExist Function\n" ;
    cout << tree.isExist(30) << '\n' ;
    cout << tree.isExist(35) << '\n' ;
    cout << "================\n" ;

    cout << "Minimum element : " ;
    cout << tree.getMin() << '\n' ;

    cout << "Maximum element : " ;
    cout << tree.getMax() << '\n' ;

    return 0;
}