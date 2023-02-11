#include<bits/stdc++.h>
using namespace std;

// 0-based indexing
void heapSort(int arr[], int n) {
    int size = n;

    while(size > 1) {
        // step-1
        swap(arr[1], arr[size]);
        size--;

        // step-2
        heapify(arr, n, 1);
    }
}