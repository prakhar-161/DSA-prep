#include<bits/stdc++.h>
using namespace std;

// Given two strings s and p, return an array of all the start indices of p's anagrams in s. 
// You may return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
// typically using all the original letters exactly once.

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> mp;
        vector<int> ans;
        
        for(auto &c : p) mp[c]++;
        
        int i=0, j=0;
        int k = p.length();
        int cnt = mp.size();
        
        while(j < s.length()) {
            if(mp.find(s[j]) != mp.end()) {
                mp[s[j]]--;
                if(mp[s[j]] == 0) {
                    cnt--;
                }
            }
            
            if(j-i+1 < k) j++;
            else if(j-i+1 == k) {
                if(cnt == 0) {
                    ans.push_back(i);
                }
                
                if(mp.find(s[i]) != mp.end()) {
                    mp[s[i]]++;
                    if(mp[s[i]] == 1) {
                        cnt++;
                    }
                }
                
                i++;
                j++;
            }
        }
        return ans;
    }
};