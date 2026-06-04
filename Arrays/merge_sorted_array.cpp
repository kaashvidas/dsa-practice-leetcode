/*
Problem: Merge Sorted Array
Platform: LeetCode #1
Difficulty: Easy

Approach:
1. Increment the left and right pointers for the two arrays 
2. Compare elements and place in the new vector 
3. Copy the new vector into the first array

Time Complexity: O(2(m+n))
Space Complexity: O(m+n)

Date Solved: 2026-06-04
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector <int> new_nums;
        int left= 0;
        int right= 0;
        while (left<m && right<n){
            if (nums1[left]<=nums2[right]){
                new_nums.push_back(nums1[left]);
                left++;
            }
            else{
                new_nums.push_back(nums2[right]);
                right++;
            }
        }
        while (left<m){
            new_nums.push_back(nums1[left]);
            left++;
        }
         while (right<n){
            new_nums.push_back(nums2[right]);
            right++;
        }

        for (int i=0; i<new_nums.size(); i++){
            nums1[i]= new_nums[i];
        }
    }
};
