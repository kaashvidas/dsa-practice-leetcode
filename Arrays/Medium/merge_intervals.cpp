/*
Problem: Merge Overlapping Intervals 
Platform: LeetCode #56
Difficulty: Medium

Approach:
1. Sort the intervals array.
2. Iterate through the arrya once, push the first interval into the ans array
3. If the first element of the second array is lesser than the second element of the intervals array back, extend the intervals array back since it is overlapping.

Time Complexity: O(n log n)+ O(n)
Space Complexity: O(n)

Date Solved: 2026-06-16
*/


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector <vector<int>> array;
        sort(intervals.begin(), intervals.end());
        
        for (int i=0; i<intervals.size(); i++){
            if (array.empty()|| array.back()[1]<intervals[i][0]){
                array.push_back(intervals[i]);
            }
            else {
                array.back()[1]= max(array.back()[1], intervals[i][1]);
            }
        }
        return array;
    }
};
