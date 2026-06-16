/*
Problem: First and Last Position of element in array
Platform: LeetCode #1
Difficulty: Medium

Approach:
1. Use binary search to locate the index of the target element 
2. To deal with the multiple occurences of the target element, keep decrementing the start index until a non-target element is found. Similarly, increment the end
index until a non-target element is found.

Time Complexity: O(log n)
Space Complexity: O(1)

Date Solved: 2026-06-16
*/

class Solution {
public:

    int binSearch(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (target > nums[mid]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        int index = binSearch(nums, target);

        // target not found
        if (index == -1) {
            return {-1, -1};
        }

        int start = index;
        int end = index;

        // move left
        while (start - 1 >= 0 && nums[start - 1] == target) {
            start--;
        }

        // move right
        while (end + 1 < nums.size() && nums[end + 1] == target) {
            end++;
        }

        return {start, end};
    }
};
