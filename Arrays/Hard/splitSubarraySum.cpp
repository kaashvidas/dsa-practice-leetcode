/*
Problem: Split Subarray- Largest Sum 
Platform: LeetCode #410
Difficulty: Hard 

Approach:
1. Use the binary search algorithm to compute the barrier value.
2. Allocate the sum in such a way that the sum cannot exceed the barrier value, if such an allocation is possible that satisfies the constraints of the number of 
subarrays, minimise the barrier value.
3. Else, look for a bigger barrier value.

Time Complexity: O(n log n)
Space Complexity: O(1)

Date Solved: 2026-06-23
*/

class Solution {
public:
    int subarrayNumber(vector <int> &nums, int barrier){
        int subarray= 1;
        long long sum=0;
        for (int i=0; i<nums.size(); i++){
            if (sum+ nums[i]<=barrier){
                sum+=nums[i];
            }
            else {
                subarray+=1;
                sum= nums[i];
            }
        }
        return subarray;
    }
    int splitArray(vector<int>& nums, int k) {
        if (k>nums.size()){return -1;}
        int low= *max_element(nums.begin(), nums.end());
        int high= accumulate(nums.begin(), nums.end(), 0);
        while (low<=high){
            int barrier= low + (high-low)/2;
            int possible= subarrayNumber(nums, barrier);
            if (possible>k){
                low= barrier+1;
            }
            else {
                high= barrier-1;
            }
        }
        return low;
        
    }
};
