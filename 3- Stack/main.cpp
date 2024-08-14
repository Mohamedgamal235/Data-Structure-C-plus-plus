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

    cout << "==============\n" ;
    cout << st.isFull() << '\n' ;
    cout << st.peek() << '\n' ;
    cout << "==============\n" ;

    st.print() ;
    cout << "==============\n" ;

    st.pop() ;
    st.print() ;
    cout << "==============\n" ;

    cout << st.isEmpty() << '\n' ;
    cout << "==============\n" ;

    st.pop();
    st.pop();
    cout << st.peek() << '\n' ;
    cout << "==============\n" ;

    st.pop();
    st.pop();
    cout << st.isEmpty() << '\n' ;
    cout << "==============\n" ;

    string str = "abc d efg xy" ;
    cout << st.reverse_subwords(str) << '\n' ;
    cout << "==============\n" ;

    int number ;
    number = 123438 ;

    cout << st.reverse_numbers(number) << '\n' ;
    cout << "==============\n" ;

    cout << st.isValidParentheses("(())") << '\n' ;    // 1
    cout << st.isValidParentheses("(()[()])") << "\n";	// 1
    cout << st.isValidParentheses("(][)") << "\n";		// 0
    cout << st.isValidParentheses("(()") << "\n";		// 0
    cout << "==============\n" ;

    cout << st.removeAdjacentDuplicates("azxxzy") << '\n' ;
    cout << st.removeAdjacentDuplicates("abbaca") << '\n' ;


    return 0;
}