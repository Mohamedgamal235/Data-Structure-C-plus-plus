#include <iostream>
#include "SkipList.h"
using namespace std ;


int main() {
    srand(time(0));

    SkipList skiplist(3, 0.5);

    skiplist.insert(3);
    skiplist.insert(6);
    skiplist.insert(7);
    skiplist.insert(9);
    skiplist.insert(12);
    skiplist.insert(19);
    skiplist.insert(25);

    skiplist.print();

    skiplist.search(19);
    skiplist.search(15);

    skiplist.remove(19);
    skiplist.print();

    return 0;
}