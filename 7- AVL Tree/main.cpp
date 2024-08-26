#include <iostream>
#include "AVLTree.cpp"
using namespace std;

int main() {

    AVLTree<int> tree ;
    // 9 6 14 7 13 32 10
    tree.insert(9) ;
    tree.insert(6) ;
    tree.insert(14);
    tree.insert(7);
    tree.insert(13);
    tree.insert(32);
    tree.insert(10);

    cout << "InOrder: ";
    tree.printInOrder(); // 6 7 9 10 13 14 32
    cout << "================\n" ;

    cout << "PostOrder: ";
    tree.printInPostOrder(); // 7 6 10 13 32 14 9
    cout << "================\n" ;

    cout << "PreOrder: ";
    tree.printInPreOrder(); // 9 6 7 14 13 10 32
    cout << "================\n" ;
    cout << "==============================================================\n" ;
    cout << "================\n" ;


    tree.remove(6) ;
    cout << "InOrder After delete (6) : ";
    tree.printInOrder(); // 7 9 10 13 14 32
    cout << "================\n" ;

    tree.remove(14) ;
    cout << "InOrder After delete (14) : ";
    tree.printInOrder(); // 7 9 10 13 32
    cout << "================\n" ;


    tree.remove(32) ;
    cout << "InOrder After delete (32) : ";
    tree.printInOrder(); // 7 9 10 13
    cout << "================\n" ;

    tree.remove(9) ;
    cout << "InOrder After delete (9) : ";
    tree.printInOrder(); // 7 10 13
    cout << "================\n" ;



    return 0;
}