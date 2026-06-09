/*
Problem: Maximum Total Subarray Value 
Platform: LeetCode #1
Difficulty: Medium

Approach:
1. Find out the max and the min element of the array
2. Since there will always be a subarray containing the max and the min element, the optimal strategy is to use the same subarray k times.
3. The total value of all the k subarray will be (k*(max-min)), which is the value to be returned.

Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 2026-06-09
*/



class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mn = INT_MAX;
        int mx = INT_MIN;

        for (int x : nums) {
            mn = min(mn, x);
            mx = max(mx, x);
        }

        return 1LL * k * (mx - mn);
    }
    
};
