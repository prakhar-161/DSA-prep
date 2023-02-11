// find total no. of occurences of an element 'k' in a sorted array
#include<bits/stdc++.h>
using namespace std;

int firstOcc(int arr[], int n, int k) {
    int start = 0, end = size - 1;
    int ans = -1;
    int mid = start + (end - start)/2;

    while(start <= end) {
        if(arr[mid] == key) {
            ans = mid;
            end = mid - 1;      // to left
        }
        
        else if(key > arr[mid]) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }

        mid = start + (end - start)/2;
    }

    return ans;
}

int lastOcc(int arr[], int n, int k) {
    int start = 0, end = size - 1;
    int ans = -1;
    int mid = start + (end - start)/2;

    while(start <= end) {
        if(arr[mid] == key) {
            ans = mid;
            start = mid + 1;      // to right
        }
        
        else if(key > arr[mid]) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }

        mid = start + (end - start)/2;
    }

    return ans;
}

int noOfOccurences(int arr[], int n, int k) {
    int firstOccIndex = firstOcc(arr, n, k);
    int lastOccIndex = lastOcc(arr, n, k);

    int numOcc = lastOccIndex - firstOccIndex + 1;
    return numOcc;
}; 
