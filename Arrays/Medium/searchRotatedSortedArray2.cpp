/*
Problem: Search in Rotated Sorted Array II (duplicates allowed)
Platform: LeetCode #81
Difficulty: Medium 

Approach:
1. Use the binary search approach.
2. For handling duplicates, add an edge case if high, low and mid elements are the same-> shrink the size of the array (increment low, decrement high).

Time Complexity: O(log n)
Space Complexity: O(1)

Date Solved: 2026-06-18
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0;
        int high= nums.size()-1;
        while (low<=high){
            int mid= low+(high-low)/2;
            if (nums[mid]==target){
                return true;
            }
            if (nums[low]==nums[mid] && nums[mid]==nums[high]){
                high--;
                low++;
                continue;
            }
            if (nums[mid]<=nums[high]){
                //right half is sorted 
                if (target>nums[mid] && target<=nums[high]){
                    low=mid+1;
                }
                else {
                    high= mid-1;
                }
            }
            else {
                //left half is sorted 
                if (target>=nums[low] && nums[mid]>target){
                    high= mid-1;
                }
                else {
                    low= mid+1;
                }
            }

        }
        return false;
        
    }
};
