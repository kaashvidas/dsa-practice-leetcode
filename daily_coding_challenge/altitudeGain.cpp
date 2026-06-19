/*
Problem: Gain in altitude 
Platform: LeetCode #1732
Difficulty: Easy

Approach:
1. Update the sum to maintain the net altitude 
2. Maintain the max sum and return.

Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 2026-06-19
*/

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi=0;
        int sum=0;
        for (int i=0; i<gain.size(); i++){
            sum+=gain[i];
            maxi= max(maxi, sum);
        }
        return maxi;
        
    }
};
