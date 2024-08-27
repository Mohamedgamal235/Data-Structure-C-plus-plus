#include <iostream>
#include "Stack.cpp"
using namespace std;

int main() {

    Stack<int> st(5) ;
    st.push(5) ;
    st.push(7) ;
    st.push(9) ;
    st.push(13) ;
    st.push(3) ;

    while (!st.isEmpty()) {
        cout << st.peek() << '\n' ;
        st.pop();
    }



    return 0;
}
