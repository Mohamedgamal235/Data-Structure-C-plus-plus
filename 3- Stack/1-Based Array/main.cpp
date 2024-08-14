#include <iostream>
#include "Stack.cpp"
using namespace std;

int main() {

    Stack<int> st(5) ;
    st.push(5);
    st.push(3);
    st.push(4);
    st.push(7);
    st.push(9);

    cout << st.isFull() << '\n' ;
    cout << st.peek() << '\n' ;

    st.print() ;

    st.pop() ;
    st.print() ;

    cout << st.isEmpty() << '\n' ;

    st.pop();
    st.pop();
    cout << st.peek() << '\n' ;

    st.pop();
    st.pop();
    cout << st.isEmpty() << '\n' ;

    string str = "abc d efg xy" ;
    cout << st.reverse_subwords(str) << '\n' ;



    return 0;
}