#include <iostream>
#include "Queue.cpp"
using namespace std;

int main() {

    Queue<int> q(5) ;

    q.enqueue(5) ;
    q.enqueue(7) ;
    q.enqueue(6) ;
    q.enqueue(8) ;
    q.enqueue(11) ;

    q.print();

    while (!q.isEmpty())
        cout << q.dequeue() << '\n' ;



    return 0;
}
