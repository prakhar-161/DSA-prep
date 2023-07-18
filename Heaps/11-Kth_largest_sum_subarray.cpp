#include<bits/stdc++.h>
using namespace std;

// similar concept to Kth largest element
// here the change is just the sum of subarrays
int getKthLargest(vector<int> &arr, int k) {
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int j=i; j<n; j++) {
            sum += arr[j];
            if(pq.size() < k) {
                pq.push(sum);
            }
            else {
                if(sum > pq.top()) {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    int ans = pq.top();
    return ans;
}