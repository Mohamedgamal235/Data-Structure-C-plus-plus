#include <iostream>
#include "RedBlackTree.cpp"
using namespace std ;

int main() {

    RedBlackTree<int> tree ;
    tree.insert(10) ;
    tree.insert(18) ;
    tree.insert(7) ;
    tree.insert(15) ;
    tree.insert(16) ;
    tree.insert(30) ;
    tree.insert(25) ;
    tree.insert(40) ;
    tree.insert(60) ;
    tree.insert(2) ;
    tree.insert(1) ;
    tree.insert(70) ;

    tree.printInOrder();
    cout << "\n=========================\n" ;


    RedBlackTree<int> tree1 ;
    tree1.insert(15) ;
    tree1.insert(30) ;
    tree1.insert(35) ;
    tree1.insert(50) ;
    tree1.insert(55) ;
    tree1.insert(65) ;
    tree1.insert(68) ;
    tree1.insert(70) ;
    tree1.insert(80) ;
    tree1.insert(90) ;

    tree1.printInOrder();
    cout << "\n=========================\n" ;
    tree1.remove(55) ;
    tree1.printInOrder();

    return 0;
}