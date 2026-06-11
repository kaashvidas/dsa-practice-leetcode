/*
Problem: Find peak element 
Platform: LeetCode #1
Difficulty: Medium 

Approach:
1. Use binary search approaach for optimal solution 
2. If the mid element is on an increasing trend, it means the peak exists on its right side else, on the left side 

Time Complexity: O(log n)
Space Complexity: O(1)

Date Solved: 2026-06-11
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=0;
        int high= nums.size()-1;

        while (low<high){
            int mid = low+ (high-low)/2;
            if (nums[mid]<nums[mid+1]){
                low= mid+1;
            }

            else {
                high=mid;
            }
        }
        return low;
    }
};
