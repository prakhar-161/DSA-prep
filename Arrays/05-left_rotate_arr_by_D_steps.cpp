#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // OPTIMAL
    void reverse(int a[], int start, int end) {
        while(start <= end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }    
    }

    void leftRotate(int arr[], int d, int n) {
        reverse(arr, arr+d);
        reverse(arr+d, arr+n);
        reverse(arr, arr+n);
    }   

    public:
    // brute force
    void rotateArr(int arr[], int d, int n){
       d = d % n;
       
       int temp[d];
       for(int i=0; i<d; i++) {
           temp[i] = arr[i];
       }
       
    //   shifting
        for(int i=d; i<n; i++) {
            arr[i-d] = arr[i];
        }
        
    // put back temp
        for(int i=n-d; i<n; i++) {
            arr[i] = temp[i - (n - d)];
        }
    } 
};