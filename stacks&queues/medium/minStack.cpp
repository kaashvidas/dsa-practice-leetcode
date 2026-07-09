/*
Problem: Min Stack 
Platform: LeetCode #155
Difficulty: Medium 

Approach:
1. Maintain a stack and a min variable.
2. While pushing, if the value is greater and doesn't alter min, push it. Else, instead of storing the actual value, store a modified value (2*value-min).

Time Complexity: O(1)
Space Complexity: O(n)

Date Solved: 2026-07-09
*/

class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() {
        mini = INT_MAX;
    }

    void push(int value) {

        if (st.empty()) {
            st.push(value);
            mini = value;
        }
        else if (value >= mini) {
            st.push(value);
        }
        else {
            st.push(2LL * value - mini);
            mini = value;
        }
    }

    void pop() {

        if (st.empty()) return;

        if (st.top() >= mini) {
            st.pop();
        }
        else {
            mini = 2LL * mini - st.top();
            st.pop();
        }

        if (st.empty())
            mini = INT_MAX;
    }

    int top() {

        if (st.top() >= mini)
            return st.top();

        return mini;
    }

    int getMin() {
        return mini;
    }
};
