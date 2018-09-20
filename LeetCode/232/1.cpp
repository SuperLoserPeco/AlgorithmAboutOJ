#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

class MyQueue {
public:
    deque<int> Q;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        Q.push_back(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int ret = Q.front();
        Q.pop_front();
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        int ret = Q.front();
        return ret;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return Q.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */