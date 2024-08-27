#include "DoublyLinkedList.cpp"
#include <iostream>
using namespace std;

int main() {
    DoublyLinkedList<int> list ;

    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.print();

    cout << list.findMiddel() << '\n' ;

    return 0;
}
