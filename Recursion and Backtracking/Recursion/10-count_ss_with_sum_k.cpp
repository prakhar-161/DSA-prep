#include<bits/stdc++.h>
using namespace std;

int printWithSumK(int ind, int sum, int k, int arr[], int n) {
    if(s > sum) return 0;   // if array contains only positives
    if(ind == n) {
        if(sum == k) return 1;
        return 0;
    }

    // pick
    sum += arr[ind];
    int l = printWithSumK(ind + 1, sum, k, arr, n);

    sum -= arr[ind];
    // not pick
    int r = printWithSumK(ind + 1, sum, k, arr, n);

    return l + r;
}

int main() {
    int arr[] = {1, 2, 1};
    int n = 3;
    int k = 2;
    cout << printWithSumK(0, 0, k, arr, n) << endl;
}