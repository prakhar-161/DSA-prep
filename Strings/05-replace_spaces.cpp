#include<bits/stdc++.h>
using namespace std;

// Method - 1
// SC -> O(N)
string replaceSpaces(string &str) {
    string temp = "";
    for(int i=0; i<str.length(); i++) {
        if(str[i] == ' ') {
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else {
            temp.push_back(str[i]);
        }
    }

    return temp;
}

// Method - 2
// SC -> O(1)
string replaceSpaces(string &str){
    int l = str.length();
    string rep = "@40";
    for(int i = 0; i<l ; i++)
    {
        if(str[i]==' ')
        {
            str.replace(i,1,rep);
        }
    }
    return str;
}