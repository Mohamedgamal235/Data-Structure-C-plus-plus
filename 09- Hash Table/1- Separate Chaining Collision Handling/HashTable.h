#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <vector>
using namespace std ;

struct StudentEntry {
private:
    static const int INTERNAL_LIMIT = 6000 ;
    string name ;
    string studentID ;

    StudentEntry(string name , string studentID) ;
    int hashFunction() ;
    void print() ;
};

class HashTable {
private:
    int tableSize ;
    vector<vector<string>> table ;

public:
    HashTable(int size);
    void insert(StudentEntry &student) ;
    bool search(StudentEntry &student) ;
    void remove(StudentEntry &student) ;
    void print() ; 

};



#endif //HASHTABLE_H
