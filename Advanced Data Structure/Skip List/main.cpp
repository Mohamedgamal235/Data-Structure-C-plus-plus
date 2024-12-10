#include <iostream>
#include "SkipList.h"
using namespace std ;


int main() {
    // srand(time(0));

    SkipList skiplist(3, 0.5);

    skiplist.insert(10);
    skiplist.insert(2);
    skiplist.insert(15);
    skiplist.insert(31);
    skiplist.insert(96);
    skiplist.insert(16);
    skiplist.print();

    skiplist.insert(71);
    skiplist.insert(87);
    skiplist.print();
    skiplist.remove(71);
    skiplist.print();
    skiplist.print();

    return 0;
}