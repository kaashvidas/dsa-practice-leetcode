/*
Problem: Next Permutation 
Platform: LeetCode #1
Difficulty: Medium

Approach:
1. Find the breakpoint by iterating from the right end of the array and the first element to break the decreasing order 
2. From the right of the breakpoint, find the element that is the smallest element greater than the breakpoint, and swap it with the breakpoint 
3. Reverse the part of the array after the breakpoint index

Time Complexity: O(n^2)
Space Complexity: O(1)

Date Solved: 2026-06-11
*/





class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n= nums.size();
        int i=n-2;

        // find the breakpoint 

        while (i>=0 && nums[i]>=nums[i+1]){
            i--;
        }

        //find the smallest element from the right greater than the breakpoint

        if (i>=0){
            int j=n-1;
            while (nums[j]<=nums[i]){
                j--;
            }

            swap(nums[i], nums[j]);
        }

        sort(nums.begin()+i+1, nums.end());
        
    }
};
