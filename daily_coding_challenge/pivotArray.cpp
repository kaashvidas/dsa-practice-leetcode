/*
Problem: Pivot Array Problem 
Platform: LeetCode #1
Difficulty: Medium 

Approach:
1. Create a new vector
2. Iterate through the array and store all the lesser elements first
3. Iterate through the array and store all the greater elements next 

Time Complexity: O(n)
Space Complexity: O(n)

Date Solved: 2026-06-08
*/




class Solution {
public:
    

    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector <int> nums_new;
        for (int i=0; i<nums.size(); i++){
            if (nums[i]<pivot){
                nums_new.push_back(nums[i]);
            }
        }
        for (int i=0; i<nums.size(); i++){
            if (nums[i]==pivot){
                nums_new.push_back(nums[i]);
            }
        }
         for (int i=0; i<nums.size(); i++){
            if (nums[i]>pivot){
                nums_new.push_back(nums[i]);
            }
        }
        return nums_new;
        
    }
};
