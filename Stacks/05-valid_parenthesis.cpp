#include<bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string expression) {
    stack<char> st;
    for(int i=0; i<expression.length(); i++) {
        char ch = expression[i];

        // if openeing bracket, push into stack
        // if closing bracket, check stack top and pop

        if(ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        else {
            // for closing bracket
            if(!st.empty()) {
                char top = st.top();
                if( (ch == ')' && top == '(') || 
                    (ch == '{' && top == '}') || 
                    (ch == '[' && top ==']') ) {
                    st.pop();
                }
                else return false;
            }
            else {
                return false;
            }
        }

        if(st.empty()) return true;
        else return false;
    }
}