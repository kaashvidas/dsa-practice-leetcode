/*
Problem: 2D Array Search 2 
Platform: LeetCode #240
Difficulty: Medium 

Approach:
1. Use the staircase approach- start from the top right corner.
2. Compare with target element at each step- if greater, eliminate the column, else eliminate row.

Time Complexity: O(m+n)
Space Complexity: O(1)

Date Solved: 2026-06-26
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row= 0;
        int col= matrix[0].size()-1;
        while (row< matrix.size() && col>=0){
            if (matrix[row][col]==target){
                return true;
            }
            else if (matrix[row][col]>target){
                col--;
            }
            else {
                row++;
            }
        }
        return false;
        
    }
};
