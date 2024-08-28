#ifndef HASHTABLE_H
#define HASHTABLE_H


#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct StudentData {
public:
    static const int INTERNAL_LIMIT = 6000;
    string name ;            // key
    string studentID ;       // value

    StudentData(string name, string studentID);
    int hashFunction() const;
    void print() const;
};

class HashTable {
private:
    int tableSize;
    vector<StudentData> table ;
    vector<bool> occupied ;
    int next(int idx) ;
public:
    HashTable(int size);
    ~HashTable();
    void insert(const StudentData& student);
    bool search(StudentData& student) const;
    void remove(const StudentData &student);
    void print() const;

};



#endif //HASHTABLE_H