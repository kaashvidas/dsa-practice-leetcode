/*
Problem: Search in Rotated Array
Platform: LeetCode #33
Difficulty: Medium 

Approach:
1. Use Binary Search to check if the left half or the right half is sorted.
2. If left half is sorted and target lies in it, search for it in the left half otherwise adjust mid to search for it in the right half & so on for the right half too.

Time Complexity: O(log n)
Space Complexity: O(1)

Date Solved: 2026-06-17
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high= nums.size()-1;
        while (low<=high){
            int mid= low+(high-low)/2;
            if (nums[mid]==target){
                return mid;
            }
            if (nums[low]<=nums[mid]){
                //left half is sorted
                if (nums[low]<=target && target<nums[mid]){
                    high=mid-1;
                }
                else {
                    low=mid+1;
                }
            }
            else {
                if (nums[mid]<target && target<=nums[high]){
                    low=mid+1;
                }
                else {
                    high=mid-1;
                }
            }

        }
    return -1;
                
    }
};
