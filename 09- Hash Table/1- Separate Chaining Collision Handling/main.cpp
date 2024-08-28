#include <iostream>
#include "HashTable.cpp"
using namespace std;


int main() {


    HashTable table(7) ;

    table.insert(StudentData("mona" , "2649")) ;        // 3
    table.insert(StudentData("amr" , "200314")) ;       // 0
    table.insert(StudentData("ali" , "200135")) ;       // 0
    table.insert(StudentData("mohamed" , "20220284")) ; // 3
    table.insert(StudentData("mena" , "26548")) ;       // 6

    table.print() ;
    cout << "///////////////////////////////////////////////////\n" ;
    table.remove(StudentData("mona" , "2649")) ;
    table.remove(StudentData("mena" , "26548")) ;

    table.print() ;


    return 0;
}