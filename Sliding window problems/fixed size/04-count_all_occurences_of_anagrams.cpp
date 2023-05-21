#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int countAnagrams(string s, string p) {
        unordered_map<char, int> mp;
        int ans = 0;

        for(auto &c : p) mp[c]++;

        int cnt = mp.size();
        int k = p.size();
        int i=0, j=0;

        while(j < s.length()) {
            // doing calcns for j
            if(mp.find(s[j]) != mp.end()) 
                mp[s[j]]--;
                if(mp[s[j]] == 0) {
                    cnt--;
                }
            }

            if(j-i+1 < k) j++;
            else if(j-i+1 == k) {
                // finding the answer
                if(cnt == 0) {
                    ans++;
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
