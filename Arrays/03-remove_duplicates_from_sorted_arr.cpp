#include<bits/stdc++.h>
using namespace std;

//GFG

class Solution {
public:	
// two-pointer approach
    int removeDups(int a[], int n) {
        int i=0; 
        for(int j=0; j<n; j++) {
            if(a[j] != a[i]) {
                a[i+1] = a[j];
                i++;
            }
        }
        return (i+1);
    }
};