/*
Problem: Largest Rectangle in Histogram
Platform: LeetCode #84
Difficulty: Hard

Approach:
1. Without precomputing the nse and pse, maintain a monotonically decreasing stack.
2. While popping out of the stack, get the element, its nse and pse and update maxArea suitably.

Time Complexity: O(2n)
Space Complexity: O(n)

Date Solved: 2026-07-11
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack <int> st;
        int maxArea=0;
        for (int i=0; i<heights.size(); i++){
            while (!st.empty() && heights[st.top()]> heights[i]){
                int element= heights[st.top()];
                st.pop();
                int nse= i;
                int pse= (st.empty())? -1: st.top();
                maxArea= max(maxArea, element* (nse-pse-1));
            }
            st.push(i);
        }
        while (!st.empty()){
            int nse= heights.size();
            int element= heights[st.top()];
            st.pop();
            int pse=(st.empty())? -1: st.top();
            maxArea= max(maxArea, element* (nse-pse-1));
        }
        return maxArea;
        
    }
};
