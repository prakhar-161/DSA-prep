#include <bits/stdc++.h>
using namespace std;

int partitionIndex(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;
    while(i < j) {
        while(arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        while(arr[j] > pivot && j >= low + 1) {
            j++;
        }
        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int n) {
    int low = 0, high = n-1;
    if(low < high) {
        int pivotIndex = partitionIndex(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high); 
    }
}