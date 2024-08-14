#include <iostream>
#include <queue>
#include <string>
#include "Stack.cpp"
using namespace std;

int main() {

    Stack<int> st(9) ;

    st.push(1,7) ;
    st.push(2,3) ;
    st.push(1,5) ;
    st.push(2,4) ;
    st.push(1,6) ;
    st.push(2,8) ;
    st.push(1,9) ;

    st.print();
    cout << "============\n" ;

    cout << st.peek(1) << '\n' ;
    cout << st.peek(2) << '\n' ;

    cout << "============\n" ;

    st.pop(1) ;
    st.pop(2) ;

    st.print() ;
    cout << "============\n" ;

    st.push(2,11) ;
    st.push(1,15) ;
    st.push(2,13) ;
    st.push(1,19) ;

    st.print();
    cout << "============\n" ;

    cout << st.isEmpty() << '\n' ;
    cout << st.isFull() << '\n' ;

    return 0;
}