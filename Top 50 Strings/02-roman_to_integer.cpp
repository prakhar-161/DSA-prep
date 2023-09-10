
// observations : 
// If smaller character or prev char (smaller) on left of current char, then, "minus" the prev char
// If smaller character on the right of current char, then, "plus" the prev char

// If non-increasing order, just add all the char values

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int value = 0;
        for(int i=0; i<s.length(); i++) {
            if(mp[s[i]] < mp[s[i+1]]) {
                value -= mp[s[i]];
            }
            else {
                value += mp[s[i]];
            }
        }

        return value;
    }
};
// TC -> O(N)
// SC -> O(N)