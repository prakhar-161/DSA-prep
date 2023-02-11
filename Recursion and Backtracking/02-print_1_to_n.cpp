// print 1 to n linearly using recursion

#include<iostream>
using namespace std;

void printN(int i, int N) {
    if(i > N) return;
    cout << i << " ";
    printN(i+1, N);  
}

int main() {
    int n;
    cin >> n;
    printN(1, n);
    return 0;
}