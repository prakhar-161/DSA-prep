#include<bits/stdc++.h>
using namespace std;

// r = size - 1

// Method - 1
int kthLargest(int arr[], int l, int r, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<r+1; i++) {
        pq.push(arr[i]);
    }

    while(pq.size() > k) {
        pq.pop();
    }
    
    int ans = pq.top();
    return ans;
}

// Method - 2
int kthLargest(int arr[], int l, int r, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<k; i++) {
        pq.push(arr[i]);
    }

    for(int i=k; k<=r; ++) {
        if(arr[i] > pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    int ans = pq.top();
    return ans;
}