#include<bits/stdc++.h>
using namespace std;

void printS(int ind, vector<int> &ds, int s, int sum, int arr[], int n) {
    if(ind == n) {
        if(s == sum) {
            for(auto it : ds) cout << it << " ";
            cout << endl;
        }
        return ;
    }

    // pick
    ds.push_back(arr[ind]);
    s += arr[ind];

    printS(ind+1, ds, s, sum, arr, n);

    ds.pop_back();
    s -= arr[ind];

    // not pick
    printS(ind+1, ds, s, sum, arr, n);
}

int main() {
    int arr[] = {3,1,2};
    int n = 3;
    int sum = 2;
    vector<int> ds;
    printS(0, ds, 0, sum, arr, n);
}