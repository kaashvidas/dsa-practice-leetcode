/*
Problem: Set Matrix Zeroes 
Platform: LeetCode #1
Difficulty: Medium 

Approach:
1. Better solution:  Create a row and a column vector, when a zero is encountered while iterating through the matrix, set the corresponding row and column
element to 1. At the end, for the row and column elements corresponding to 1, set them to 0.

2. Optimal Solution: Instead of creating separate vectors for row and column, integrate it within the matrix by assigning the 0th row as column vector and 0th 
column as the row vector, along with a separate variable cols0 for the 0th column to avoid overlapping. Firstly, iterate through the matrix and mark the 
corresponding row and column vectors as 0. Second, skip the 0th row and column and iterate through the other elements first, and according to the row and column,
mark them zero and then finally mark the 0th row and column elements. This is how the space complexity was reduced and the operations were done in place.


Time Complexity: O(m*n)
Space Complexity: O(1)

Date Solved: 2026-06-13
*/



class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0=1;
        int rows= matrix.size();
        int cols= matrix[0].size();

        for (int i=0; i<rows; i++ ){
            for (int j=0; j<cols; j++){
                if (matrix[i][j]==0){
                    matrix[i][0]=0;
                    if (j!=0){
                        matrix[0][j]=0;
                    }
                    else {
                        col0=0;
                    }
                }

            }
        }

        for (int i=1; i<rows; i++){
            for (int j=1; j<cols; j++){
                if (matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }

        if (matrix[0][0]==0){
            for (int j=1; j<cols; j++){
                matrix[0][j]=0;
            }
        }

        if (col0==0){
            for (int i=0; i<rows; i++){
                matrix[i][0]=0;
            }

        }
        
    }
};
