// print n to 1 linearly using backtracking

#include<iostream>
using namespace std;

void func(int i, int N) {
    if(i > N) return;
    
    printN(i+1, N);  
    cout << i << " ";
}

int main() {
    int n;
    cin >> n;
    func(1, n);
    return 0;
}