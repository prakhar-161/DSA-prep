// Find first and last occurence of an element 'k' in a sorted array
#include<bits/stdc++.h>
using namespace std;

// return index of first occurence of element 'k'
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

pair<int, int> firstAndLastPosition(int arr[], int n, int k) {
    int firstOccIndex = firstOcc(arr, n, k);
    int lastOccIndex = lastOccIndex(arr, n, k);
    pair<int, int> p;
    p.first = firstOcc(arr, n, k);
    p.second = lastOcc(arr, n, k);
    return p;
}