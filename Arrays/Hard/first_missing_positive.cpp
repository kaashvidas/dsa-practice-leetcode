/*
Problem: First Missing Positive 
Platform: LeetCode #1
Difficulty: Hard 

Approach:
1. The first missing positive number would be within [1, n+1] (n is the size of the array)
2. Ideal place of each element should be at the index i-1, i.e ideally, nums[i]= i+1;
3. Scan the array and place the element at its ideal place 
4. At the end, scan the array again to check for the first element that does not satisfy the above condition.

Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 2026-06-05
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            while (
                nums[i] > 0 &&
                nums[i] <= n &&
                nums[i] != nums[nums[i] - 1]
            ) {

                swap(
                    nums[i],
                    nums[nums[i] - 1]
                );
            }
        }

        for (int i = 0; i < n; i++) {

            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return n + 1;
    }
};
