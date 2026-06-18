/*
Problem: Limit Occurences of Element
Platform: LeetCode #3940
Difficulty: Easy

Approach:
1. Keep a write pointer j.
2. If j<k, keep it and add to arrat (in=place).
3. If not, check if the element has been the same for more than k times, if yes, skip, else add. 
4. Resize the vector to return only the valid portion of the array. 

Time Complexity: O(n)
Space Complexity: O(1) 

Date Solved: 2026-06-18
*/

class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int j=0;
        for (int i=0; i<nums.size(); i++){
            if (j<k|| nums[i]!=nums[j-k]){
                nums[j++]=nums[i];
            }
        }
        nums.resize(j); //only return the valid portion of the array
      return nums;        
    }
};
