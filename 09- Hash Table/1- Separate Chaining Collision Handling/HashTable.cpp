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
    cout << "Name: " << name << "\nID: " << studentID << "\n==============\n";
}

// ==================================================== //
// =========== Implementation of Class ================ //
// ==================================================== //

HashTable::HashTable(int size) : tableSize(size), table(size) {}

void HashTable::insert(const StudentData& student) {
    int key = student.hashFunction() % tableSize;

    for (auto& data : table[key]) {
        if (data.name == student.name) {
            data = student; 
            return;
        }
    }

    table[key].push_back(student);
}


void HashTable::print() const {
    for (int hash = 0; hash < tableSize; hash++) {
        if (table[hash].empty())
            continue;

        cout << "Hash " << hash << ": ";
        for (const auto& student : table[hash]) {
            student.print();
        }
    }
}
