// You are given a string s, partition it in such a way that every substring is a palindrome. 
// Return all such palindromic partitions of s.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPlindrome(string s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }

    void func(int index, string s, vector<string> &part, vector<vector<string>> &ans) {
        if(index == s.size()) {
            ans.push_back(part);
            return;
        }

        for(int i = index; i < s.size(); i++) {
            if(isPalindrome(s, index, i) == true) {
                part.push_back(s.substr(index, i - index + 1));
                func(i+1, s, part, ans);
                part.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;
        func(0, s, part, ans);
        return ans;
    }
};