#include <iostream>
#include <vector>
#include "BinaryHeap.cpp"
using namespace std;

int main() {

    MinHeap<int> minHeap ;
    vector<int> arr {2, 17, 22, 8, 10, 14, 37, 19, 7, 6, 5, 12, 25, 30} ;
    for (int i = 0 ; i < arr.size() ; i++)
        minHeap.insert(arr[i]) ;

    cout << "============Test=MinHeap =========\n";
    cout << "==================================\n";
    cout << "after insertions:" << endl;
    minHeap.print();
    cout << "==================\n";
    cout << "==================\n";

    minHeap.insert(3);
    cout << "after inserting 3:" << endl;
    minHeap.print();
    cout << "==================\n";
    cout << "==================\n";

    minHeap.remove();
    cout << "after removing :" << endl;
    minHeap.print();
    cout << "==================\n";


    cout << "\n******************\n";
    cout << "******************\n\n";


    MaxHeap<int> maxHeap;
    for (int i = 0; i < arr.size(); i++)
        maxHeap.insert(arr[i]);

    cout << "============Test=MaxHeap=========\n";
    cout << "==================================\n";
    cout << "after insertions:" << endl;
    maxHeap.print();
    cout << "==================\n";

    maxHeap.insert(40);
    cout << "after inserting 40:" << endl;
    maxHeap.print();
    cout << "==================\n";

    maxHeap.remove();
    cout << "after removing the maximum element:" << endl;
    maxHeap.print();
    cout << "==================\n";


    return 0;
}