/*
Problem: Next Greater Element II
Platform: LeetCode #503
Difficulty: Medium

Approach:
1. For the indices, hypothetically double the array and access the indices using modulo.
2. Then do the same montonically decreasing stack algorithm for the new hypothetical array.

Time Complexity: O(2n)
Space Complexity: O(n)+ O(n)

Date Solved: 2026-07-10
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size());
        stack <int> st;
        for (int i= 2*nums.size()-1; i>=0; i--){
            while (!st.empty() && st.top()<=nums[i%nums.size()]){
                st.pop();
            }
            if (i<nums.size()){
                int x= st.empty()?-1: st.top();
                ans[i]=x;
            }
            st.push(nums[i%nums.size()]);
        }
      
        return ans;
        
    }
};
