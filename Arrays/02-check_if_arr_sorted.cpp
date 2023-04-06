#include<bits/stdc++.h>
using namespace std;

//GFG

class Solution {
public:	
    bool checkArrSorted(int arr[], int n) {
        for(int i=0; i<n-1; i++) {
            if(arr[i] > arr[i+1]) {
                return false;
            }
        }
        return true;
    }
};