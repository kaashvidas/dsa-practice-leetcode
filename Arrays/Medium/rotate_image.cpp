/*
Problem: Rotate Image (rotate the 2d matrix by 90)
Platform: LeetCode #1
Difficulty: Medium 

Approach:
1. Transpose the matrix 
2. Reverse each row 

Time Complexity: O(n^2)
Space Complexity: O(1)

Date Solved: 2026-06-14
*/



class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int rows= matrix.size();
        int cols= matrix[0].size();

        for (int i=0; i<rows-1; i++){
            for (int j=i+1; j<cols; j++){
                swap(matrix[j][i], matrix[i][j]);
                
            }
        }

        for (int i=0; i<rows; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
    }
};
