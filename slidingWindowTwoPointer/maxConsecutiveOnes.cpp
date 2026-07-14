/*
Problem: Maximum Consecutive Ones 
Platform: LeetCode #1004
Difficulty: Medium 

Approach:
1. Maintain two pointers- right and left, iterate through the array until right exceeds array size.
2. Increment zeros when right element equals zero, trim the zeros when left element is zero.

Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 2026-07-15
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int right =0;
        int left=0;
        int maxi=0;
        int zeros=0;
        while (right<nums.size()){
            if (nums[right]==0){
                zeros++;
            }
            if (zeros>k){
                if (nums[left]==0){
                    zeros--;
                }
                left++;
            }
            if (zeros<=k){
                int len= right-left+1;
                maxi= max(maxi, len);
            }
            right++;
        }
        return maxi;
        
    }
};
