// GFG
// Given two binary max heaps as arrays, merge the given heaps to form a new max heap.

#include<bits/stdc++.h>
using namespace std;

// 0-based indexing

class Solution{
    private:
    void maxHeapify(vector<int> &merged, int N, int i) {
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;
        
        if(left < N && merged[largest] < merged[left]) {
            largest = left;
        }
        if(right < N && merged[largest] < merged[right]) {
            largest = right;
        }
        
        if(largest != i) {
            swap(merged[largest], merged[i]);
            maxHeapify(merged, N, largest);
        }
    }
    
    void buildMaxHeap(vector<int> &merged, int N) {
        for(int i=N/2-1; i>=0; i--) {
            maxHeapify(merged, N, i);
        }
    }
    
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> merged(n+m);
        for(int i=0; i<n; i++) {
            merged[i] = a[i];
        }
        
        for(int i=0; i<m; i++) {
            merged[n+i] = b[i];
        }
        
        buildMaxHeap(merged, n+m);
        return merged;
    }
};

// ssh user02@172.16.64.194