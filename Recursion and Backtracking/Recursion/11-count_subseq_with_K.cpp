#include<bits/stdc++.h>
using namespace std;

int printS(int ind, int s, int sum, int arr[], int n) {
    // condition not satisfied
    // strictly done if array contains positives only
    if(s > sum) return 0;
    if(ind == n) {
        if(s == sum) 
            return 1;
        else return 0;
    }

    // pick
    // ds.push_back(arr[ind]);
    s += arr[ind];
    int l = printS(ind+1, s, sum, arr, n);

    // ds.pop_back();
    s -= arr[ind];

    // not pick
    int r = printS(ind+1, s, sum, arr, n);

    return l + r;
}

int main() {
    int arr[] = {3,1,2};
    int n = 3;
    int sum = 2;
    // vector<int> ds;
    cout << printS(0, 0, sum, arr, n);

    return 0;
}