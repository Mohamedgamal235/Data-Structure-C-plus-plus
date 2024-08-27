#include "SinglyLinkedList.cpp"
#include <iostream>
using namespace std;

int main() {
    SinglyLinkedList<int> list ; 
    list.insertAtHead(5); 
    list.insertAtHead(8); 
    list.insertAtHead(9); 
    list.insertAtHead(12); 
    list.insertAtHead(3);
    list.print();


    return 0;
}
