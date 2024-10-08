#include  <iostream>
#include "BinaryTree.cpp"
using namespace std;

int main() {

    BinaryTree<int> tree(1) ;

    tree.insert({2,4 ,7} , {'L','L','L'}) ;
    tree.insert({2,5,9} , {'L' , 'R' , 'R'});
    tree.insert({2,4,8} , {'L' , 'L' , 'R'});
    tree.insert({3,6,10} , {'R' , 'R' , 'L'});

    tree.printInOrder() ; // 7 4 8 2 5 9 1 3 10 6
    tree.printInPostOrder(); // 7 8 4 9 5 2 10 6 3 1
    tree.printInPreOrder() ; // 1 2 4 7 8 5 9 3 6 10

    tree.clear() ;
    tree.printInPostOrder() ;

    cout << "==================\n" ;



    return  0 ;
}
