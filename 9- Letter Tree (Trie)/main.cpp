#include <iostream>

#include "Trie.h"
using namespace std;

int main() {

    Trie str ;

    str.insert("abcd") ;
    str.insert("xyz") ;
    str.insert("abf") ;

    cout << "=== 0 -> False ==== 1 -> True ===\n" ;


    cout << "\n=== Test wordExist function ==== \n" ;
    cout << "abc : " << str.wordExist("abc") << '\n' ;
    cout << "abcd : " << str.wordExist("abcd") << '\n' ;
    cout << "abf : " << str.wordExist("abf") << '\n' ;

    cout << "=============================\n" ;

    cout << "=== Test prefixExist function ==== \n" ;
    cout << "ab : " << str.prefixExist("ab") << '\n' ;
    cout << "bf : " << str.prefixExist("bf") << '\n' ;
    cout << "af : " << str.prefixExist("af") << '\n' ;
    cout << "xz : " << str.prefixExist("xz") << '\n' ;


    return 0;
}