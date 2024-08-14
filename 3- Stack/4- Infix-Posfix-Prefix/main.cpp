#include <iostream>
#include "Stack.cpp"
using namespace std;

int main() {

    Stack<int> st ;

    cout << st.infixToPostfix("1+4*3-5") << '\n';
    cout << st.infixToPostfix("1+3*(5+4^3-5)") << '\n' ;
    cout << st.infixToPostfix("a+b*(c^d-e)^(f+G*h)-i") << '\n' ;
    cout << "================\n" ;

    cout << st.postfixEvaluation("134*+4+") << '\n' ;


    return 0;
}