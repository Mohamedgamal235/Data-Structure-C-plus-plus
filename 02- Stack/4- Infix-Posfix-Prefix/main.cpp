#include <iostream>
#include "Stack.cpp"
using namespace std;

int main() {

    Stack<int> st ;

    cout << "=============== Infix To Posftix ============= \n" ;
    cout << st.infixToPostfix("1+4*3-5") << '\n' ;
    cout << st.infixToPostfix("2+(3*(4-5)*(9/3+6))") << '\n' ;
    cout << st.infixToPostfix("(1+2)^3^(4-6)^2+1") << '\n' ;
    cout << st.infixToPostfix("2^3^4^5^6") << '\n' ;
    cout << st.infixToPostfix("a+(c^d-e)^(f+g*h)-i") << '\n' ;
    cout << st.infixToPostfix("1+2^3^4-6") << '\n' ;
    cout << st.infixToPostfix("a+b*(c^d-e)^(f+G*h)-i") << '\n' ;
    cout << "================\n" ;

    cout << "\n=============== Posftix Evaluation ============= \n" ;
    cout << st.postfixEvaluation(st.infixToPostfix("1+4*3-5")) << '\n' ;
    cout << st.postfixEvaluation(st.infixToPostfix("2+(3*(4-5)*(9/3+6))")) << '\n' ;
    cout << st.postfixEvaluation(st.infixToPostfix("(1+2)^3^(4-6)^2+1")) << '\n' ;
    cout << st.postfixEvaluation(st.infixToPostfix("1+2^3^4-6")) << '\n' ;
    cout << "================\n" ;

    cout << "=============== Infix To Prefix ============= \n" ;
    cout << st.infixToPrefix("1+4*3-5") << '\n' ;
    cout << st.infixToPrefix("2+(3*(4-5)*(9/3+6))") << '\n' ;
    cout << st.infixToPrefix("(1+2)^3^(4-6)^2+1") << '\n' ;
    cout << st.infixToPrefix("2^3^4^5^6") << '\n' ;
    cout << st.infixToPrefix("a+(c^d-e)^(f+g*h)-i") << '\n' ;
    cout << st.infixToPrefix("1+2^3^4-6") << '\n' ;
    cout << st.infixToPrefix("a+b*(c^d-e)^(f+G*h)-i") << '\n' ;


    return 0;
}