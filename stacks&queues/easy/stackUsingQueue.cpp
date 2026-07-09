/*
Problem: Implement Stack using queue
Platform: LeetCode #225
Difficulty: Easy

Approach:
1. In the push function, push the element and then pop and insert at the end of the queue.
2. All other functions remain the same.

Time Complexity: O(1)
Space Complexity: O(n)

Date Solved: 2026-07-09
*/

class MyStack {
public:
    queue <int> q;

    MyStack() {
        
    }
    
    void push(int x) {
        int s= q.size();
        q.push(x);
        for (int i=0; i<s; i++){
            q.push(q.front());
            q.pop();
        }
        
    }
    
    int pop() {
        int el= q.front();
        q.pop();
        return el;
        
    }
    
    int top() {
        return q.front();
        
    }
    
    bool empty() {
        return q.empty();
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
