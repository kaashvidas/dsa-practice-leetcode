/*
Problem: Find Minimum Element in Rotated Sorted Array
Platform: LeetCode #153
Difficulty: Meidum 

Approach:
1. Use binary search to compare the mid element with the high at each step and update low and high accordingly.
2. At the end, return the element at the low index.

Time Complexity: O(log n)
Space Complexity: O(1)

Date Solved: 2026-06-17
*/


class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int high= nums.size()-1;

        while (low<high){
            int mid= low+ (high-low)/2;
            if (nums[mid]>nums[high]){
                low= mid+1;
            }
            else {
                high=mid;
            }
        }
        return nums[low];        
    }
};
