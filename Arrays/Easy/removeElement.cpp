/*
Problem: Remove Element 
Platform: LeetCode #1
Difficulty: Easy

Approach:
1. Use two pointers 
2. Swap out the val elements with the end elements

Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 2026-06-11
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int i = 0;
        int n = nums.size();

        while (i < n) {

            if (nums[i] == val) {

                nums[i] = nums[n - 1];

                n--;
            }
            else {
                i++;
            }
        }

        return n;
    }
};
