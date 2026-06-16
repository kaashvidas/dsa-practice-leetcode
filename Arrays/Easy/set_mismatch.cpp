/*
Problem: Set Mismatch
Platform: LeetCode #645
Difficulty: Easy

Approach:
1. Use the math approach for reducing space complexity, by making use of the sum of natural numbers and sum of squares of natural numbers formula, then solving
the linear equations to find out the missing and the repeated number.
2. The brute force solution was storing the elements into an unordered map.

Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 2026-06-16
*/


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long actualSum=0;
        long long actualSquare=0;
        int n=nums.size();
        for (int i=0; i<nums.size(); i++){
            actualSum+=nums[i];
            actualSquare+=1LL*nums[i]*nums[i];
        }
        long long expectedSum= n* (n+1)/2;
        long long expectedSquare=1LL* n* (n+1)*(2*n+1)/6;

        long long diff= actualSum-expectedSum;
        int sum= (actualSquare- expectedSquare)/(diff);
        int repeated= (sum+diff)/2;
        int missing = sum-repeated;
        return {repeated, missing};
        
        
    }
};
