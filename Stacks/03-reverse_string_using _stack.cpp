#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    stack<char> st;
    for(char const &c : s) {
        st.push(c);
    }   

    string ans = "";
    while(!st.empty()) {
        char x = st.top();
        ans.push_back(x);
        st.pop();
    }    
    cout << ans << endl;
    return 0;
}