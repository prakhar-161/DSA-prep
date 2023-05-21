// LEETCODE
// Given a string s and an integer k, 
// return the maximum number of vowel letters in any substring of s with length k.
// Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        char t = tolower(c);
        return t == 'a' or t == 'e' or t=='i' or t=='o' or t=='u';
    }
    
    int maxVowels(string s, int k) {
        int i = 0, j = 0, maxi = INT_MIN, count = 0;
        while(j < s.length()) {
            if(isVowel(s[j])) {
                count++;
            }
            
            if(j - i + 1 < k) j++;
            else if(j - i + 1 == k) {
                maxi = max(maxi, count);
                if(isVowel(s[i])) {
                    count--;
                }
                i++;
                j++;
            }
        }
        return maxi;
    }
};