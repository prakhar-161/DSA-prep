#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    priority_queue<int> s;      // max-heap
    priority_queue<int, vector<int>, greater<int>> g;       // min-heap

    void insertHeap(int &x) {
        if(s.size() == 0) {
            s.push(x);
            return;
        }

        // when s.size() is not equal to g.size()
        if(s.size() > g.size()) {
            if(x > s.top()) {
                g.push(x);
            }
            else {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
        }
        // when s.size() is equal to g.size()
        else {
            if(x > s.top()) {
                g.push(x);
                s.push(g.top());
                g.pop();
            }
            else {
                s.push(x);
            }
        }
    }

    double getMedian() {
        if(s.size() == g.size()) {
            return (double)(s.top() + g.top()) / 2.0;
        }
        else {
            return s.top();
        }
    }

};