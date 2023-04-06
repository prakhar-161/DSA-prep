#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void selectionSort(int arr[], int n) {
        int i, j, minIndex;
        for(i=0; i<n-1; i++) {
            minIndex = i;
            for(j=i+1; j<n; i++) {
                if(arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
                // swap
                int temp = arr[minIndex];
                arr[minIndex] = arr[i];
                arr[i] = temp;
            }
        }
    }
};