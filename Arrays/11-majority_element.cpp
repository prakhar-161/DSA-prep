#include<bits/stdc++.h>
using namespace std;

// MOORE Voting Algorithm

class Solution{
  public:
    int majorityElement(int a[], int n) {
        int cnt = 0;
        int ele;
        for(int i=0; i<n; i++) {
            if(cnt == 0) {
                // starting the check for a new section in the array
                ele = a[i];
                cnt = 1;
            }
            else if(a[i] == ele) {
                cnt++;
            }
            else {
                cnt--;
            }
        }

        int cnt1 = 0;
        for(int i=0; i<n; i++) {
            if(a[i] == ele) cnt1++;
        }
        if(cnt1 > (n/2)) {
            return ele;
        }
        return -1;
    }
};