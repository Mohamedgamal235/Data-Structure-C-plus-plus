#include <iostream>
#include "HashTable.h"
using namespace std;

int main() {


    HashTable table(7) ;

    table.insert(StudentData("mona" , "2649")) ;        // 3
    table.insert(StudentData("amr" , "200314")) ;       // 0
    table.insert(StudentData("ali" , "200135")) ;       // 0
    table.insert(StudentData("mohamed" , "20220284")) ; // 3
    table.insert(StudentData("mena" , "26548")) ;       // 6

    table.print() ;

    cout << "===================================================\n" ;
    table.remove(StudentData("mohamed" , "20220284" )) ;
    cout << "After remove mohamed : \n" ;

    table.print() ;

    cout << "===================================================\n" ;
    cout << "Search for mohamed : " << table.search(StudentData("mohamed" , "20220284")) << '\n' ;
    cout << "Search for mena : " << table.search(StudentData("mena" , "26548")) << '\n' ;


    return 0;
}