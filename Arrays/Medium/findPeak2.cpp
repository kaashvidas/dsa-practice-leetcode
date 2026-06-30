/*
Problem: Find peak element II
Platform: LeetCode #1901
Difficulty: Medium 

Approach:
1. Go through binary search on columns 
2. In the given column find the row index of the largest element 
3. If that element is greater than its right and left elements, return its indices else, eliminate the left or the right columns accordingly

Time Complexity: O(log (m))
Space Complexity: O(1)

Date Solved: 2026-06-30*/

class Solution {
public:
    int maxIndex(vector <vector<int>> &mat, int m, int n, int col){
        int maxi=-1;
        int index=-1;
        for (int i=0; i<m; i++){
            if (mat[i][col]>maxi){
                maxi= mat[i][col];
                index= i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m= mat.size();
        int n= mat[0].size();
        int low=0;
        int high= n-1;
        while (low<=high){
            int mid= low+ (high-low)/2;
            int maxi= maxIndex(mat, m, n, mid);
            int left= mid-1>=0? mat[maxi][mid-1]: -1;
            int right= mid+1<n? mat[maxi][mid+1]: -1;
            if (mat[maxi][mid]> left && mat[maxi][mid]>right){
                return {maxi, mid};
            }
            else if (mat[maxi][mid]<left){
                high= mid-1;
            }
            else {
                low= mid+1;
            }
            
        }
        return {-1, -1};
        
    }
};
