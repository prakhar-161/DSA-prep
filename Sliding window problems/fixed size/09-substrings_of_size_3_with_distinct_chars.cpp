// A string is good if there are no repeated characters.
// Given a string s​​​​​, return the number of good substrings of length three in s​​​​​​.
// Note that if there are multiple occurrences of the same substring, every occurrence should be counted.

// SIMILAR TO MAX_SUM_OF_DISTINCT_ARRAYS_WITH_LENGTH_K
// same template used

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countGoodSubstrings(string s) {
        unordered_map<char, int> mp;
        int i=0, j=0, count=0;
        while(j < s.length()) {
            mp[s[j]]++;
            
            if(j-i+1 < 3) j++;
            else if(j-i+1 == 3) {
                if(mp.size() == 3) {
                    count++;
                }
                
                mp[s[i]]--;
                if(mp[s[i]] == 0) {
                    mp.erase(s[i]);
                }
                
                i++;
                j++;
            }
        }
        
        return count;
    }
};