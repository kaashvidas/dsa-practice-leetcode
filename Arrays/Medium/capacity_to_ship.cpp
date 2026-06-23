/*
Problem: Capacity to ship packages within d days
Platform: LeetCode #1011
Difficulty: Medium 

Approach:
1. Use the Binary Search Algorithm to find the barrier.
2. If the package shipment in a day is possible within the given barrier try to further minimise the capcacity barrier, else increase the barrier.
3. Return the minimum capacity.

Time Complexity: O(n log n)
Space Complexity: O(1)

Date Solved: 2026-06-23
*/


class Solution {
public:
    bool possible(vector <int> &weights, int barrier, int days){
        int day=1;
        int total=0;
        for (int weight: weights){
            if (total+weight<=barrier){
                total+=weight;
            }
            else {
                day+=1;
                total=weight;
            }
        }
        return day<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low= *max_element(weights.begin(), weights.end());
        int high= accumulate(weights.begin(), weights.end(),0);
        int ans=high;

        while (low<=high){
            int barrier= low+(high-low)/2;
            if (possible(weights, barrier, days)){
                high=barrier-1;
                ans= barrier;
            }
            else {
                low= barrier+1;
            }
        }
        return ans;
        
    }
};
