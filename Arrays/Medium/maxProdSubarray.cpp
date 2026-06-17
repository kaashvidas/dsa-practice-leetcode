/*
Problem: Maximum Product Subarray
Platform: LeetCode #152
Difficulty: Medium 

Approach:
1. Using Kadane's Algorithm like the one in the Max Sum Subarray problem will not be effective here, since products will handle negatives and zero in a different way.
2. Track both the minimum and the maximum products encountered while iterating through the array (dynamic programming), when a negative number is encountered, swap. 
3. Update the ans with the maxProd at each step while iterating. 

Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 2026-06-17
*/



class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd= nums[0];
        int minProd= nums[0];
        int ans=nums[0];

        for (int i=1; i<nums.size(); i++){
            if (nums[i]<0){
                swap(maxProd, minProd);
            }
            maxProd= max(nums[i], maxProd*nums[i]);
            minProd= min(nums[i], minProd*nums[i]);
            ans= max(ans, maxProd);
        }
        return ans;
    }
};
