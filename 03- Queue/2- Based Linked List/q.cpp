#include <iostream>
#include "Queue.cpp"
using namespace std;

int main() {
    Queue<int> q;
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(8);
    q.enqueue(9);

    cout << "Size: " << q.size() << '\n';
    cout << "First element: " << q.first_element() << '\n';
    cout << "Last element: " << q.last_element() << '\n';
    q.print();

    q.dequeue();
    cout << "After dequeue:\n";
    q.print();
    cout << "Size: " << q.size() << '\n';

    return 0;
}
