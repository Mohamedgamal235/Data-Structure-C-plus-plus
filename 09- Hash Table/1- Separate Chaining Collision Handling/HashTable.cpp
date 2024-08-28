#include "HashTable.h"


long long hashString(string &str , int n) {
    long long bigN = n ;
    long long sum = 0 ;
    for (int i = 0 ; i < str.size() ; i++) {
        sum = ( sum * 26 + str[i] - 'a' ) % bigN ;
    }
    return sum % bigN ;
}

// ==================================================== //
// =========== Implementation of  Struct ============== //
// ==================================================== //

StudentData::StudentData(string name, string studentID) {
    this->name = name ;
    this->studentID = studentID ;
}

int StudentData::hashFunction() {
    return hashString(name , INTERNAL_LIMIT) ;
}




















