#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        int xor1 = 0, xor2 = 0;
        for(int i=0; i<n-1; i++) {
            xor2 = xor2 ^ array[i];
            xor1 = xor1 ^ (i+1);
        }
        xor1 = xor1 ^ n;
        return (xor1 ^ xor2);
    }
};