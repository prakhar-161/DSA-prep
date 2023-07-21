#include<bits/stdc++.h>
using namespace std;

void printWithSumK(int ind, int sum, int k, int arr[], vector<int> &ds, int n) {
    if(ind == n) {
        if(sum == k) {
            for(auto it : ds) cout << it << " ";
            cout << endl;
        }
        return;
    }

    // pick
    ds.push_back(arr[ind]);
    sum += arr[ind];
    printWithSumK(ind + 1, sum, k, arr, ds, n);

    ds.pop_back();
    sum -= arr[ind];
    // not pick
    printWithSumK(ind + 1, sum, k, arr, ds, n);
}

int main() {
    int arr[] = {1, 2, 1};
    int n = 3;
    int k = 2;
    vector<int> ds;
    printWithSumK(0, 0, k, arr, ds, n);
}