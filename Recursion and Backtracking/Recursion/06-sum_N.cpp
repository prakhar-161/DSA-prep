#include<bits/stdc++.h>
using namespace std;

// Parameterized Recursion
void sumNP(int i, int sum) {
    if(i < 1) {
        cout << sum << endl;
        return;
    }

    sumNP(i-1, sum+i);
}

// Functional Recursion
int sumNF(int n) {
    if(n == 0) return 0;

    return n + sumNF(n-1);
}

int main() {
    int n;
    cin >> n;
    // sumNP(n, 0);
    cout << sumNF(n) << "\n";
    return 0;
}