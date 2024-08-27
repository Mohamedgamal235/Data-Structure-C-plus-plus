#include <iostream>
#include "Queue.cpp"
using namespace std;

int main() {
    Queue<int> q(5) ;

    q.enqueue(5) ;
    q.dequeue();
    q.enqueue(6) ;
    q.enqueue(3) ;
    q.enqueue(7) ;
    q.enqueue(8) ;


    q.print();

    return 0;
}