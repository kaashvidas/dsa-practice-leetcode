/*
Problem: Maximum Subarray
Platform: LeetCode #1
Difficulty: Medium

Approach:
1. Compute sum for consecutive elements, starting from the first and iterating throughout the array
2. Use Kadane's Algorithm for optimal solution- reset the sum to 0 if it gets negative (because negative sum will decrease the further elements)
3. Only keep track of the maximum sum

Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 2026-06-11
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum= 0;
        int maxi= nums[0];

        for (int i=0; i<nums.size(); i++){
            sum+=nums[i];
            maxi= max(maxi, sum);

            if (sum<0){
                sum=0;
        }
    }
    return maxi;
    }
};
