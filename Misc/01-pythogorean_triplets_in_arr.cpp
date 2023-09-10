#include<bits/stdc++.h>
using namespace std;

// BETTER solution 
class Solution {
public:
    bool isTriplet(int arr[], int n) {
        for(int i=0; i<n; i++) {
            arr[i] = arr[i] * arr[i];
        }

        sort(arr, arr+n);

        for(int i=n-1; i>=2; i++) {
            
        }
    }
};

// Brute solution
class Solution {
public:
    bool isTriplet(int ar[], int n) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    // Calculate square of array elements
                    int x = ar[i] * ar[i], y = ar[j] * ar[j], z = ar[k] * ar[k];
    
                    if (x == y + z || y == x + z || z == x + y)
                        return true;
                }
            }
        }
 
        // If we reach here, no triplet found
        return false;
    }
};
// TC -> O(N^3)
