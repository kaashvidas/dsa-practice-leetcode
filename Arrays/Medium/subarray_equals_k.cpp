/*
Problem: Subarray equals K 
Platform: LeetCode #1
Difficulty: Medium 

Approach:
1. Iterate through the array and store the sum of elements upto that element at each step as the prefix sum in an unordered hashmap.
2. At each step, look for the number of occurences of (sum-k) in the hashmap as it will equal the number of subarray that sum to k.

Time Complexity: O(n)
Space Complexity: O(n)

Date Solved: 2026-06-14
*/



class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int preSum=0, count=0;
        unordered_map <int, int> mpp;
        mpp[0]=1;
        for (int i=0; i<nums.size(); i++){
            preSum+=nums[i];
            int remove= preSum-k;
            count+=mpp[remove];
            mpp[preSum]++;
        }
        return count;
        
    }
};
