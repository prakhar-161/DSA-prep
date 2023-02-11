// print 1 to n linearly using backtracking

#include<iostream>
using namespace std;

void printN(int i, int N) {
    if(i < 1) return;
    
    printN(i-1, N);  
    cout << i << " ";
}

int main() {
    int n;
    cin >> n;
    printN(n, n);
    return 0;
}