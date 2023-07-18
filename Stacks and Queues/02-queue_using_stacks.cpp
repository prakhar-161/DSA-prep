// Method - 1 -> most optimal
// push -> O(1)
// pop -> O(N) and O(1) amortized
// auxiliary space -> O(N)
class MyQueue {
public:
    stack<int> ip, op;
    MyQueue() {
        
    }
    
    void push(int x) {
        ip.push(x);
    }
    
    int pop() {
        if(op.empty()) {
            while(!ip.empty()) {
                op.push(ip.top());
                ip.pop();
            }
        }

        int valToBeDeleted = op.top();
        op.pop();
        return valToBeDeleted;
    }
    
    int peek() {
        if(op.empty()) {
            while(!ip.empty()) {
                op.push(ip.top());
                ip.pop();
            }
        }
        return op.top();
    }
    
    bool empty() {
        return ip.empty() && op.empty();
    }
};

// Method - 2 (less optimal)
// push -> O(N)
// pop -> O(1)
class MyQueue {
public:
    stack<int> s1, s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

         while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        if (s1.empty()) {
            return -1;
        }
 
        // Return top of s1
        int x = s1.top();
        s1.pop();
        return x;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};