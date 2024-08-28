#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <vector>
using namespace std ;

struct StudentData {
private:
    static const int INTERNAL_LIMIT = 6000 ;
    string name ;
    string studentID ;

    StudentData(string name , string studentID) ;
    int hashFunction() ;
    void print() ;
};

class HashTable {
private:
    int tableSize ;
    vector<vector<string>> table ;

public:
    HashTable(int size);
    void insert(StudentData &student) ;
    bool search(StudentData &student) ;
    void remove(StudentData &student) ;
    void print() ;

};



#endif //HASHTABLE_H
