/*
Problem: Search Insert Position 
Platform: LeetCode #1
Difficulty: Easy

Approach:
1. Return the index of the position at which target value is found 
2. If not found, return the index at which it should be inserted in the sorted array

Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 2026-06-11
*/


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int pos= -1;
        for (int i=0; i<nums.size(); i++){
            if (nums[i]==target){
                return i;
            }
            if (nums[i]<target){
                pos= i+1;
            }
            
        }

        if (pos==-1) {return 0;}
        return pos;
        
    }
};
