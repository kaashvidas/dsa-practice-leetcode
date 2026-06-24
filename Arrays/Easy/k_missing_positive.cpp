/*
Problem: Find k missing positive 
Platform: LeetCode #1539
Difficulty: Easy

Approach:
1. Use the binary search algorithm to check the number of missing numbers at each index and find the two indices between which the number must lie.
2. At the end add arr[high] and more (k-missing).

Time Complexity: O(log n)
Space Complexity: O(1)

Date Solved: 2026-06-24
*/


class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=0;
       int high= arr.size()-1;
        while (low<=high){
            int mid= low+ (high-low)/2;
            int missing= arr[mid]- (mid+1);
            if (missing<k){
                low= mid+1;
            }
            else {
                high= mid-1;
            }
        }
        return low+k;
    }
};
