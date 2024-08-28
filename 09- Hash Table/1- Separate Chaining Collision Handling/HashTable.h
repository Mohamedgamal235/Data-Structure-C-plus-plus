

#ifndef HASHTABLE_H
#define HASHTABLE_H


#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct StudentData {
public:
    static const int INTERNAL_LIMIT = 6000;
    string name;
    string studentID;

    StudentData(string name, string studentID);
    int hashFunction() const;
    void print() const;
};

class HashTable {
private:
    int tableSize;
    vector<vector<StudentData>> table;

public:
    HashTable(int size);
    ~HashTable();
    void insert(const StudentData& student);
    bool search(StudentData& student) const;
    void remove(const StudentData &student);
    void print() const;
};



#endif //HASHTABLE_H
