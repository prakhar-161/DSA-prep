#include<bits/stdc++.h>
using namespace std;

// Max-heap (building it)
// 1-based indexing
void heapify(int arr[], int n, int i) {
    // take the largest element to its correct place

    // One-based indexing
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[largest] < arr[left]) {
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]) {
        largest = right;
    }

    // if largest index is updated from above
    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}   

int main() {
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i=n/2; i>0; i--) {
        heapify(arr, n, i);
    }
    cout << "Modified array :";
    for(int i=1; i<=n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
} 

// 0-based indexing
// left = 2*i+1;
// right = 2*i+2;