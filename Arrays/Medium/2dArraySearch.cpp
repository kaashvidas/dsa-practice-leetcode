/*
Problem: earch in 2D Matrix
Platform: LeetCode #74
Difficulty: Medium 

Approach:
1. Since the rows and columns are sorted in themselves, perform the binary search on the first element of the rows, to locate the correct row and then perform binary
search on that row.

Time Complexity: O(log (m*n))
Space Complexity: O(1)

Date Solved: 2026-06-26
*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix[0][0]>target){
            return false;
        }
        int m= matrix.size();
        int low=0;
        int high= m-1;
        while (low<=high){

            int mid= low+ (high-low)/2;
            int n= matrix[mid].size();
            if (matrix[mid][0]>target){
                high= mid-1;
            }
            else if (matrix[mid][n-1]< target){
                low= mid+1;
            }
            else {
                int low_new=0;
                int high_new=n-1;
                while (low_new<=high_new){
                    int mid_new= low_new+ (high_new-low_new)/2;
                    if (matrix[mid][mid_new]==target){
                        return true;
                    }
                    else if (matrix[mid][mid_new]>target){
                        high_new= mid_new-1;
                    }
                    else {
                        low_new= mid_new+1;
                    }
                }
                return false;
            }
        }
        return false;
        
    }
};
