#include<bits/stdc++.h>
using namespace std;

int singlenumber(int a[],int N) {
    int xor1 = 0;
    for(int i=0; i<n; i++) {
        xor1 = xor1 ^ a[i];
    }
    return xor1;
}