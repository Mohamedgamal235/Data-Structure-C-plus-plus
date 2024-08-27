#include <iostream>
#include "Deque.cpp"
using namespace std;

int main() {

    Deque<int> dq(6) ;

    dq.enqueue_front(3); // 3
    dq.print(); // 3

    dq.enqueue_front(2); // 2 3
    dq.enqueue_back(4); // 2 3 4
    dq.enqueue_front(1); // 1 2 3 4
    dq.enqueue_front(5); // 5 1 2 3 4
    dq.enqueue_front(6); // 6 5 1 2 3 4
    dq.print();	// 6 5 1 2 3 4

    cout<<dq.get_back()<<"\n";	// 4
    dq.dequeue_back() ;
    dq.print();	// 6 5 1 2 3

    cout<< dq.get_front()<<"\n"; // 6
    dq.dequeue_front();
    dq.print();	// 5 1 2 3

    cout<<dq.get_back()<<"\n";	// 3
    dq.dequeue_back() ;
    dq.print(); // 5 1 2

    cout<<dq.get_front()<<"\n";	// 5
    dq.dequeue_front();
    dq.print(); // 1 2

    while(!dq.isEmpty())
        dq.dequeue_back();

    for (int i = 0; i < 6; ++i)
        dq.enqueue_back(i+10);
    dq.print();	//

    while(!dq.isEmpty())
        dq.dequeue_back();
    // dq.print();

    return  0 ;
}