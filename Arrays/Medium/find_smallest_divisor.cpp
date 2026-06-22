/*
Problem: Find Smallest Divisor below Threshold Sum
Platform: LeetCode #1283
Difficulty: Medium 

Approach:
1. Use the Binary Search algorithm to iterate through the array of numbers between 1 and the max element 
2. Calculate the sum for each divisor and compare with threshold 


Time Complexity: O(n log (max(n)))
Space Complexity: O(1)

Date Solved: 2026-06-22
*/

class Solution {
public:
    int calculateSum(vector <int> &nums, int divisor){
        int sum=0;
        for (int num: nums){
            sum+= (num+divisor-1)/divisor;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high= *max_element(nums.begin(), nums.end());
        int ans=high;
        while (low<=high){
            int mid= low+(high-low)/2;
            int sum= calculateSum(nums, mid);
            if (sum<=threshold){
                ans= mid;
                high= mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return ans;
        
    }
};
