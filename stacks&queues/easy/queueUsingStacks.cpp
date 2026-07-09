/*
Problem: Implement Queue using stacks 
Platform: LeetCode #232
Difficulty: Easy

Approach:
1. Maintain two stacks- s1 and s2.
2. For the push operation, empty s1 and push into s2, push the new element into s1, empty all elements from s2 back into s1.
3. All other operations follow normal stack operations.

Time Complexity: O(1)
Space Complexity: O(n)

Date Solved: 2026-07-09
*/

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue() {

    }

    void push(int x) {

        // Move everything from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push new element
        s1.push(x);

        // Move everything back
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        int el = s1.top();
        s1.pop();
        return el;
    }

    int peek() {
        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }
};
