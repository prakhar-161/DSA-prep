#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> v) {
    int n = v.size();
    int cnt = 0, ele;
    for(int i=0; i<n; i++) {
        if(cnt == 0) {
            cnt = 1;
            ele = v[i];
        }
        else if(v[i] == ele) cnt++;
        else cnt--;
    }
    // verification 
    // if it is provided that majority element may or may not exist
    int cnt1 = 0;
    for(int i=0; i<n; i++) {
        if(v[i] == ele) cnt1++;
    }
    if(cnt1 > (n/2)) return cnt1;
    return -1;
}