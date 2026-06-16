/*
Problem: Product of Array except Self 
Platform: LeetCode #1
Difficulty: Medium 

Approach:
1. Store the prefix products (products of all the elements on the left side of the element) in the ans array first. Then iterate backwards and multiply
each element in the answer array with the suffix (product of all the elements on the right side of the element).

Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 2026-06-16
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        vector <int> ans(n, 1);
        int prefix=1;

        for (int i=0; i< nums.size(); i++){
            ans[i]=prefix;
            prefix*=nums[i];
        }
        int suffix=1;

        for (int i=n-1; i>=0; i--){
            ans[i]*=suffix;
            suffix*=nums[i];
        }
        return ans;
        
    }
};
