/*
Problem: Row with Maximum Ones 
Platform: LeetCode #2643
Difficulty: Easy

Approach:
1. Iterate through the 2d array and update the maxCount variable accordingly.

Time Complexity: O(m*n)
Space Complexity: O(1)

Date Solved: 2026-06-26
*/

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxCount=-1;
        int index=0;

        for (int i=0; i<mat.size(); i++){
            int count=0;
            for (int j=0; j<mat[i].size(); j++){
               count+=mat[i][j];
            }
            if (count>maxCount){
                maxCount=count;
                index=i;
            }
        }
        return {index, maxCount};
        
    }
};
