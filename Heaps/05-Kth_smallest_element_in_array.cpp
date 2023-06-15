// GFG
// Given an array arr[] and an integer K where K is smaller than size of array,
// the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function

    // METHOD - 1
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> pq;

        for(int i=0; i<k; i++) {
            pq.push(arr[i]);
        }
        
        for(int i=k; i<=r; i++) {
            if(arr[i] < pq.top()) {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        int ans = pq.top()
        return ans;
    }

    // METHOD - 2 (Better to understand)
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> pq;
        for(int i=0; i<r+1; i++) {
            pq.push(arr[i]);
        }

        while(pq.size() > k) {
            pq.pop();
        }

        int ans = pq.top();
        return ans;
    }
};