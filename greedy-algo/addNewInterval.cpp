/*
Problem: Insert New Interval
Platform: LeetCode #57
Difficulty: Medium 

Approach:
1. Divide the intervals array into three segments- the left part (without overlapping), the centre (merging intervals) & the right part (without overlapping).
2. Add the left part as it is, merge the centre part and then add and then, add the right part as it is.

Time Complexity: O(n)
Space Complexity: O(n)

Date Solved: 2026-07-19
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector <vector <int>> ans; int i=0;
        while(i< intervals.size() && newInterval[0]> intervals[i][1]){
            ans.push_back(intervals[i]);
            i++;
        }
        while (i<intervals.size() && newInterval[1]>= intervals[i][0]){
            newInterval[0]= min(newInterval[0], intervals[i][0]);
            newInterval[1]= max(newInterval[1], intervals[i][1]);
            i++;
        }
           ans.push_back(newInterval);
        while (i<intervals.size()){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;        
    }
};
