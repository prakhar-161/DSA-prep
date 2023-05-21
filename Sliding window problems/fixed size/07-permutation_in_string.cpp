// LEETCODE
// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
// In other words, return true if one of s1's permutations is the substring of s2.

#include<bits/stdc++.h>
using namespace std;

// similar to count occurences of anagram solution.

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp;
        for(auto &c : s1) mp[c]++;
        
        int k = s1.length();
        int cnt = mp.size();
        int i = 0, j = 0;
        while(j < s2.length()) {
            if(mp.find(s2[j]) != mp.end()) {
                mp[s2[j]]--;
                if(mp[s2[j]] == 0) {
                    cnt--;
                }
            }
            
            if(j - i + 1 < k) j++;
            else if(j - i + 1 == k) {
                if(cnt == 0) return true;
                    
                if(mp.find(s2[i]) != mp.end()) {
                    mp[s2[i]]++;
                    if(mp[s2[i]] == 1) cnt++;
                }
                
                i++;
                j++;
            }
        }
        return false;
    }
};