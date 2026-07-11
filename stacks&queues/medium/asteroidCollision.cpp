/*
Problem: Asteroid Collision 
Platform: LeetCode #735
Difficulty: Medium 

Approach:
1. Maintain a stack for the asteroids- push the positive asteroids as it is.
2. For the negative asteroids, check the top of the stack. If top is negative, push. If top is positive and the magnitude of the top is greater, do not push.
If the magnitude of the incoming asteroid is greater, pop the top of the stack and compare with the next.


Time Complexity: O(n)+ O(2n)
Space Complexity: O(n)+ O(n)

Date Solved: 2026-07-11
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int i = 0; i < asteroids.size(); i++) {

            if (asteroids[i] > 0) {
                st.push(asteroids[i]);
            }
            else {

                while (!st.empty() && st.top() > 0 &&
                       st.top() < abs(asteroids[i])) {
                    st.pop();
                }

                if (st.empty() || st.top() < 0) {
                    st.push(asteroids[i]);
                }
                else if (st.top() == abs(asteroids[i])) {
                    st.pop();
            }
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
