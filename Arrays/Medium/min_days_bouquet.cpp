/*
Problem: Minimum days required to make m bouquets
Platform: LeetCode #1482
Difficulty: Medium

Approach:
1. Use the binary search approach to solve for the min days.
2. If k adjacent flowers are available to make m bouquets, ie, the allocation is possible within the mid number of days, searc in the left half of the array, else
search for in the right half of the array.

Time Complexity: O(n log n)
Space Complexity: O(1)

Date Solved: 2026-06-23
*/

class Solution {
public:
    bool possible(vector <int>&bloomDay, int m, int k, int day){
        int flowers=0;
        int bouquet=0;
        for (int i=0; i<bloomDay.size(); i++){
            if (bloomDay[i]<=day){
                flowers++;
                if (flowers==k){
                    bouquet+=1;
                    flowers=0;
                }
            }
            else {
                flowers=0;
            }
        }
        return bouquet>=m;
        
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (1LL*m*k>bloomDay.size()){return -1;}  

        int low=*min_element(bloomDay.begin(), bloomDay.end());
        int high= *max_element(bloomDay.begin(), bloomDay.end());
        while (low<=high){
            int mid= low+(high-low)/2;
            if (possible(bloomDay, m, k, mid)){
                high= mid-1;
            }
            else {
                low= mid+1;
            }
        }
        return low;      
    }
};
