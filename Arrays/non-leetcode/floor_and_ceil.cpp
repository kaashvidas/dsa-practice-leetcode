/*
Problem: Floor and Ceil of an element in the array
Difficulty: Medium 

Approach:
1. Use binary search approach
2. Store the values for floor and ceil and update at each step while comparing with the mid element.

Time Complexity: O(log n)
Space Complexity: O(1)

Date Solved: 2026-06-17
*/

class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int low=0;
        int high= nums.size()-1;
        int floor=-1;
        int ceil=-1;
        while (low<=high){
            int mid= low+(high-low)/2;
            if (nums[mid]==x){
                return {x,x};
            }
            else if (nums[mid]>x){
                ceil=nums[mid];
                high= mid-1;                
            }
            else {
                floor= nums[mid];
                low=mid+1;
            }
        }
        return {floor, ceil};
   
    }
};
