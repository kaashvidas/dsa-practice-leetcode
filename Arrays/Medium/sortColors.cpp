/*
Problem: Sort Colors 
Platform: LeetCode #75
Difficulty: Medium 

Approach:
1. Use the Dutch National Flag Algorithm to sort.
2. Maintain four regions- 0 to low for zeroes, low to mid for 1, mid to high for unsorted and high to end for 2, and swap mid appropriately.

Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 2026-07-07
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0;
        int mid=0;
        int high= nums.size()-1;

        while (mid<=high){
            if (nums[mid]==0){
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            else if (nums[mid]==1){
                mid++;
            }
            else {
                swap(nums[high], nums[mid]);
                high--;
            }
        }
        
    }
};
