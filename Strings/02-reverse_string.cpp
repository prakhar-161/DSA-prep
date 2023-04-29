#include<bits/stdc++.h>
using namespace std;

void reverse(char str[], int n) {
    int start = 0, end = n-1;
    while(start < end) {
        swap(str[start++], str[end--]);
    }
}