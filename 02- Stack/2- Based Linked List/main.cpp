#include <iostream>
#include "Stack.cpp"
using namespace std;

int main() {

    Stack<int> st ;
    st.push(5) ;
    st.push(8) ;
    st.push(9) ;
    st.push(11) ;

    st.print();

    st.pop();

    cout << st.peek() << '\n' ;

    return 0;
}