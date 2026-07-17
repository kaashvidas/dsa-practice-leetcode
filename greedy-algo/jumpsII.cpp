/*
Problem: Jump Game II
Platform: LeetCode #45
Difficulty: Medium 

Approach:
1. Maintain the left and the right pointer.
2. For every range, compute the farthest index you can jump to, and them update the pointers to update the range and increment jumps.

Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 2026-07-17
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int left=0; int right=0;
        int jumps=0;
        while (right<nums.size()-1){
            int farthest=0;
            for (int i= left; i<=right; i++){
                farthest= max(farthest, nums[i]+i);
            }
            left= right+1;
            right= farthest;
            jumps++;           
        }
        return jumps;
        
    }
};
