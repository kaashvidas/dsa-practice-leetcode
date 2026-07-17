/*
Problem: Jump Game 
Platform: LeetCode #55 
Difficulty: Medium 

Approach:
1. Iterate through the array and keep a track of the maximum index you can reach by jumping from that position.
2. If at any point, the index exceeds the max index, break off and return false.

Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 2026-07-17
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIdx=0;
        for (int i=0; i<nums.size(); i++){
            if (i>maxIdx){
                return false;
            }
            maxIdx= max(maxIdx, i+nums[i]);
        } 
        return true;       
    }
};
