#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        int mini = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j] < min) {
                mini = j;
            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
} 