/*
Problem: Set Matrix Zeroes 
Platform: LeetCode #1
Difficulty: Medium 

Approach:
1. Better solution:  Create a row and a column vector, when a zero is encountered while iterating through the matrix, set the corresponding row and column
element to 1. At the end, for the row and column elements corresponding to 1, set them to 0.


Time Complexity: O(m*n)
Space Complexity: O(m+n)

Date Solved: 2026-06-13
*/



class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows= matrix.size();
        int cols= matrix[0].size();

        vector <int> row(rows, 0);
        vector <int> col(cols, 0);

        for (int i=0; i<rows; i++){
            for (int j=0; j<cols; j++){
                if (matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }

        for (int i=0; i<rows; i++){
            for (int j=0; j<cols; j++){
                if (row[i]|| col[j]){
                    matrix[i][j]=0;
                }
            }
        }
        
    }
};
