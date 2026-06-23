/*
Problem: Koko eating bananas 
Platform: LeetCode #875
Difficulty: Medium 

Approach:
1. Use the binary search algorithm to find the min speed.
2. Divide the piles with the speed and return the sum of ceil.
3. If the sum of cel is within h, minimise k by searching in the left half, else search in the right half. 

Time Complexity: O(n log n)
Space Complexity: O(1)

Date Solved: 2026-06-23
*/


class Solution {
public:
    long long calculateSum(vector <int> &piles, int k){
        long long sum=0;
        for (int num: piles){
             sum += (num+k-1)/k;
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high= *max_element(piles.begin(), piles.end());
        while (low<=high){
            int mid= low+(high-low)/2;
            long long sum= calculateSum(piles, mid);
            if (sum<=h){
                high= mid-1;
            }
            else {
                low= mid+1;
            }
        }
        return low;
        
    }
};
