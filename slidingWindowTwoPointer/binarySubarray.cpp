/*
Problem: Binary Subarray with Sum 
Platform: LeetCode #930
Difficulty: Medium

Approach:
1. Maintain two pointers- left and right. Increment right and while is lesser than goal, add to count, all the possible subarrays formed with the new element.
2. Return the count of all subarrays lesser than equal to goal minus the count of subarrays lesser than equal to goal-1.

Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 2026-07-15
*/

class Solution {
public:
    int atMostSum(vector <int> &nums, int goal){
         int left=0;
        int right=0;
        int count=0;
        int sum=0;
        while (right<nums.size()){
            if (goal<0){
                return 0;
            }
            sum= sum+nums[right];
            while (sum>goal){
                sum-=nums[left];
                left++;
            }
            count+=(right-left+1);
            right++;
        }
       return count; 
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMostSum(nums, goal)- atMostSum(nums, goal-1);       
    }
};
