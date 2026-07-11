/*
Problem: Maximum Sliding Window
Platform: LeetCode #239
Difficulty: Hard 

Approach:
1. Maintain a deque- a monotonically decreasing one. 
2. Pop the elements that are out of the sliding window since they are no longer required.
3. Add to the ans list from the front of the deque as you move forward since its monotonically decreasing.

Time Complexity: O(n)
Space Complexity: O(n)

Date Solved: 2026-07-12 
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque <int> dq;
        vector <int> ans;
        for (int i=0; i<nums.size(); i++){
            if (!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if (i>=k-1) {
                ans.push_back(nums[dq.front()]);
            }

        }
        return ans;
        
    }
};
