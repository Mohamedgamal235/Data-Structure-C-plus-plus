#include <iostream>
#include "BinarySearchTree.cpp"
using namespace std;

int main() {

    BinarySearchTree<int> tree ;

    tree.insert(50) ;
    tree.insert(20) ;
    tree.insert(15) ;
    tree.insert(60) ;
    tree.insert(70) ;
    tree.insert(73) ;
    tree.insert(45) ;
    tree.insert(35) ;

    cout << "InOrder: ";
    tree.printInOrder(); // 15 20 35 45 50 60 70 73
    cout << "\n================\n" ;

    cout << "PostOrder: ";
    tree.printInPostOrder(); // 15 35 45 20 73 70 60 50
    cout << "\n================\n" ;

    cout << "PreOrder: ";
    tree.printInPreOrder(); // 50 20 15 45 35 60 70 73
    cout << "\n================\n" ;

    cout << "Level Order : ";
    tree.printLevelOrider(); // 50 20 60 15 45 70 35 73
    cout << "\n================\n" ;

    cout << "isExist Function\n" ;
    cout << tree.isExist(30) << '\n' ; // 0
    cout << tree.isExist(35) << '\n' ; // 1
    cout << "================\n" ;

    cout << "Minimum element : " ;
    cout << tree.getMin() << '\n' ; // 15

    cout << "Maximum element : " ;
    cout << tree.getMax() << '\n' ; // 73 

    return 0;
}