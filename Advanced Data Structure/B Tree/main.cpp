#include "BTree.cpp"
#include <iostream>
using namespace std ;

int main (){

    // Construct a BTree of order 3, which stores int data
    BTree<int,3> t1;
    t1.insert(1);
    t1.insert(5);
    t1.insert(0);
    t1.insert(4);
    t1.insert(3);
    t1.insert(2);
    t1.print(); // Should output the following on the screen:
    /*
    1,4
      0
      2,3
      5
    */
    // Construct a BTree of order 5, which stores char data

    cout << "============\n" ;
    BTree<char,5> t;
    // Look at the example in our lecture:
    t.insert('G');
    t.insert('I');
    t.insert('B');
    t.insert('J');
    t.insert('C');
    t.insert('A');
    t.insert('K');
    t.insert('E');
    t.insert('D');
    t.insert('S');
    t.insert('T');
    t.insert('R');
    t.insert('L');
    t.insert('F');
    t.insert('H');
    t.insert('M');
    t.insert('N');
    t.insert('P');
    t.insert('Q');
    t.print(); // Should output the following on the screen:
    /*
    K
      C,G
        A,B
        D,E,F
        H,I,J
      N,R
        L,M
        P,Q
        S,T
    */
    return 0;
}