#include <bits/stdc++.h>
using namespace std;

void countSort(int arr[], int n) {
    int maxi = arr[0];
    // maxi - for size of count array
    for(int i=0; i<n; i++) {
        maxi = max(maxi, arr[i]);
    }

    int count[10] = {0};
    for(int i=0; i<n; i++) {
        count[arr[i]]++;
    }

    // prefix sum calculation
    for(i=1; i<=k; i++) {
        count[i] += count[i-1];
    }

    // putting count[arr[i]]-- into output array
    int output[n];
    for(int i=n-1; i>=0; i--) {
        output[--count[arr[i]]];
    }

    for(int i=0; i<n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int arr[] = {1,3,2,3,4,1,6,4,3};
    for(int i=0; i<9; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}