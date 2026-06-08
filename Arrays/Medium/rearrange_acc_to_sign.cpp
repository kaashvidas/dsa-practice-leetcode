/*
Problem: Rearrange the elements according tto sign
Platform: LeetCode #1
Difficulty: Medium 

Approach:
1. Create a new vector 
2. Maintain two pointers- one for positive and the other for negative elements 
3. Through conditions alternately store the elements 

Time Complexity: O(n)
Space Complexity: O(n)

Date Solved: 2026-06-08
*/


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector <int> new_vector;
        int j=0;
        int k=0;
        for (int i=0; i<nums.size(); i++){
            if (i%2==0){
                while (nums[j]<0){
                    j++;
                }
                new_vector.push_back(nums[j]);
                j++;  
            }
            else {
                while (nums[k]>0){
                    k++;
                }
                new_vector.push_back(nums[k]);
                k++;
            }
        }
        return new_vector;
    }
};
