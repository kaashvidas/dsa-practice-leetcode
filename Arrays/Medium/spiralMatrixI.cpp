/*
Problem: Spiral Matrix I
Platform: LeetCode #1
Difficulty: Medium

Approach:
1. Maintain the four pointers-> right. left, top and bottom
2. Traverse in the spiral order, push to the answer vector and increment & decrement the pointers accordingly 
3. Check for edge cases-> single row or single column matrices 



Time Complexity: O(n^2)
Space Complexity: O(1)

Date Solved: 2026-06-14
*/




class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows= matrix.size();
        int cols= matrix[0].size();
        int top=0; int left=0;
        int right= cols-1;
        int bottom= rows-1;
        vector <int> ans;

        while (top<=bottom && left<=right){
            for (int i=left; i<=right; i++){
            ans.push_back(matrix[top][i]);
        }
        top++;

        

        for (int i=top; i<=bottom; i++){
            ans.push_back(matrix[i][right]);
        }
        right--;

        if (top<=bottom){
            for (int i=right; i>=left; i--){
            ans.push_back(matrix[bottom][i]);
        }
        bottom--;
        }
        if (left<=right){
            for (int i=bottom; i>=top; i--){
            ans.push_back(matrix[i][left]);
        }
        left++;
        }

        }
        return ans;        
        
    }
};
