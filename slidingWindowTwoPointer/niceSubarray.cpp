/*
Problem: Count Number of Nice Subarrays 
Platform: LeetCode #1248
Difficulty: Medium 

Approach:
1. Maintain the two pointers- right and left for keeping a track of the sliding window.
2. While the number of odd numbers in the window is under k, increment the number of possible subarrays, when it exceeds k, trim the window and depending upon whether 
the left element s odd or even adjust the odd counter accordingly.

Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 2026-07-16
*/


class Solution {
public:
    int atMostCount(vector <int> &nums, int k){
        int right=0;
        int left=0;
        int count=0;
        int odd=0;
        while (right<nums.size()){
            if (nums[right]%2==1){
                odd++;
            }
            while (odd>k){
                if (nums[left]%2==1){
                    odd--;
                }
                left++;
            }
            count+=right-left+1;
            right++;
        }
        return count;
        
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostCount(nums, k)- atMostCount(nums, k-1);
    }
};
