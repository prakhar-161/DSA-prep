
// one-to-one mapping
// no many-to-one mapping 
// no one-to-many mapping

// Approach
// two maps
// 1st map : char, char     (which char is mapped to which char)
// 2nd map : char, bool     (string2 ka konsa char use ho chuka hai)

class Solution {
public:
    bool isIsomorphic(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if(n != m) return false;

        unordered_map<char, char> m1;
        unordered_map<char, bool> m2;
        for(int i=0; i<n; i++) {
            char ch1 = s1[i];
            char ch2 = s2[i];

            if(m1.find(ch1) != m1.end()) {              // if s1[i] is already present in m1
                if(m1[ch1] != ch2) return false;        // if there is one to many, return false
            }
            else {
                if(m2.find(ch2) != mp.end()) {          // if char from s2 is already used but is not mapped in map1 till now (many to one)
                    return false;
                }
                else {
                    m1[ch1] = ch2;
                    m2[ch2] = true;
                }
            }
        }
        return false;
    }
};