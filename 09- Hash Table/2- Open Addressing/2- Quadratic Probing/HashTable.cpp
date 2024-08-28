#include "HashTable.h"

long long hashString(const string& str, int n) {
    long long bigN = n;
    long long sum = 0;
    for (int i = 0; i < (int)str.size(); i++) {
        sum = (sum * 26 + str[i] - 'a') % bigN;
    }
    return sum % bigN;
}

// ==================================================== //
// =========== Implementation of Struct =============== //
// ==================================================== //

StudentData::StudentData(string name, string studentID) {
    this->name = name;
    this->studentID = studentID;
}

int StudentData::hashFunction() const {
    return hashString(name, INTERNAL_LIMIT);
}

void StudentData::print() const {
    cout << "Name: " << name << " , ID: " << studentID ;
}

// ==================================================== //
// =========== Implementation of Class ================ //
// ==================================================== //


HashTable::HashTable(int size) : tableSize(size), table(size), occupied(size, false) {}

//---------------

HashTable::~HashTable() {
    table.clear();
    occupied.clear();
    tableSize = 0;
}

//---------------

int HashTable::quadraticProbing(int idx , int i) const {
    return (idx + i * i) % tableSize ;
}

//---------------

void HashTable::insert(const StudentData &student) {
    int idx = student.hashFunction() % tableSize ;

    for (int i = 0 ; i < tableSize ;i++) {
        int currIdx = quadraticProbing(idx , i) ;
        if (!occupied[currIdx]) {
            occupied[currIdx] = true ;
            table[currIdx] = student ;
            return;
        }
    }

    cout << "Hash table is full \n" ; // if full not found any empty place to insert
}







