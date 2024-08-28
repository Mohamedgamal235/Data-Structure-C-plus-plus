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
    cout << "Name: " << name << " , ID: " << studentID <<  " ||| " ;
}

int HashTable :: next(int idx) {
    int newIndex = idx ;
    while (occupied[newIndex])
        newIndex = (newIndex + 1 ) % tableSize ;

    return newIndex ;
}

// ==================================================== //
// =========== Implementation of Class ================ //
// ==================================================== //

HashTable::HashTable(int size) : tableSize(size), table(size) {}

// ---------

HashTable::~HashTable() {
    table.clear() ;
    tableSize = 0 ;
}

// ---------

void HashTable::insert(const StudentData& student) {
    int idx = student.hashFunction() % tableSize ;

    if (!occupied[idx])
        table[idx] = student , occupied[idx] = true ;
    else {
        int newIdx = next(idx) ;
        occupied[newIdx] = true ;
        table[newIdx] = student ;
    }
}

// ---------

bool HashTable::search(StudentData &student) const {
    int idx = student.hashFunction() % tableSize ;

    for (int i = 0 ; i < tableSize ; i++) {
        int currIdx = (idx + i ) % tableSize ;
        if (occupied[currIdx] && table[currIdx].name == student.name)
            return true ;

        if (!occupied[currIdx])
            break;
    }

    return false ;
}


// ---------

void HashTable::remove(const StudentData &student) {
    int idx = student.hashFunction() % tableSize ;

    for (int i = 0 ; i < tableSize ; i++) {
        int currIdx = (idx + i) % tableSize ; 
        if (occupied[currIdx] && table[currIdx].name == student.name) {
            occupied[currIdx] = false ;
            return; 
        }

        if (occupied[currIdx] == false) {
            cout << "Not found to remove \n" ;
            return;
        }
    }
}


// ------------------

void HashTable::print() const {
    for (int i = 0; i < tableSize; i++) {
        if (occupied[i]) {
            table[i].print();
            cout << '\n' ;
        }
    }
}
