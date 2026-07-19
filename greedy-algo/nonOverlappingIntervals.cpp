/*
Problem: Non-Overlapping Intervals
Platform: LeetCode #435
Difficulty: Medium 

Approach:
1. Sort the intervals in ascending order of their ends.
2. Iterate through the intervals and increment count only if the next interval begins after the previous one end, else skip.
3. Return total intervals minus the count.

Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 2026-07-19
*/

class Solution {
public:
    static bool compare(vector <int> &interval_1, vector <int> &interval_2){
        return interval_1[1]< interval_2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int count=1; int last=intervals[0][1];
        for (int i=1; i<intervals.size(); i++){
            if (intervals[i][0]>= last){
                count++;
                last= intervals[i][1];
            }
        }
        return intervals.size()-count;
        
    }
};
