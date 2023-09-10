#include<bits/stdc++.h>
using namespace std;

// Do we have to trim the spaces?
// Do we have to reverse the individual words or reverse their positions in the string?

// Method - 2
// Using two pointer

// Approach - 
// 1. Reverse whole string first
// 2. Individually reverse all words and trim down the spaces if extra
class Solution {
public:
    string reverseWords(string s) {
        // reverse whole string
        reverse(s.begin(), s.end());

        // 2nd step
        int i = 0;
        // l and r reverse the individual words in reversed string
        int l = 0, r = 0;

        while(i < n) {
            while(i < n && s[i] != ' ') {            // i encounters a character, it gives it to 'r' and i++, r++
                s[r] = s[i];
                r++;
                i++;
            }

            if(l < r) {
                reverse(s.begin() + l, s.begin() + r);
                s[r] = ' ';
                r++;

                l = r;
            }

            i++;
        }

        s = s.substr(0, r-1);
        return s;
    }
};


// ---------------------------------------------------------------------------------------------------------------------

// Method - 1
// Using tokenizer - String stream
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token = "";
        string result = "";
        // By default, string stream tokenizes on ' ' (space char)
        while(ss >> token) {
            result = token + " " + result;
        }
        // "world_hello_"
        return result.substr(0, result.length() - 1);
    }
};
