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
    void insert(const StudentData& student);
    bool search(const string& name, StudentData& result) const;
    bool remove(const string& name);
    void print() const;
};

#endif // HASHTABLE_H
