/*
Problem: Single Element in Sorted Array
Platform: LeetCode #540
Difficulty: Medium 

Approach:
1. Use Binary Search Approach.
2. Before the single element appears, the pairs start at even indices, adjust mid to be even at the start of each iteration.
3. The single element shifts the pairs to start from odd indices (elements occuring after the single start from odd indices).

Time Complexity: O(log n)
Space Complexity: O(1)

Date Solved: 2026-06-17
*/


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;

        while (low<high){
            int mid= low+(high-low)/2;
            if (mid%2!=0){
                mid--;
            }
            if (nums[mid]==nums[mid+1]){
                low=mid+2;
            }
            else if (nums[mid]!=nums[mid+1]){
                high=mid;
            }
        }
        return nums[low];
        
    }
};
