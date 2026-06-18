/*
Problem: First Unique Even Element
Platform: LeetCode #3866
Difficulty: Easy

Approach:
1. Store elements in hashmap.
2. Iterate through the array once and return the first even element with value 1, if none exists return -1.

Time Complexity: O(n)
Space Complexity: O(n)

Date Solved: 2026-06-18
*/

class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map <int, int> mpp;
        for (int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }
        for (int i=0; i<nums.size(); i++){
            if (nums[i]%2==0 && mpp[nums[i]]==1){
                return nums[i];
        }
    }
        return -1;
    }
};
