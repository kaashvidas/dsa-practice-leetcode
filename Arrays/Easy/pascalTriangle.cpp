/*
Problem: Pascal's Triangle 
Platform: LeetCode #1
Difficulty: Easy

Approach:
1. For each row, the total no of elements are equal to the row number and the formula is equal to the combination formula. 

Time Complexity: O(numRows^2)
Space Complexity: O(numsrows^2)

Date Solved: 2026-06-14
*/


class Solution {
public:
    vector <int> generateRow(int row){
        vector <int> ansRow;
        ansRow.push_back(1);
        long long ans=1;
        for (int col=1; col<row; col++){
            ans= ans* (row-col);
            ans=ans/(col);
            ansRow.push_back(ans);
        }
        return ansRow;
    }
    vector<vector<int>> generate(int numRows) {
        vector <vector <int>> ans;
        for (int i=1; i<=numRows; i++){
            ans.push_back(generateRow(i));
        }
        return ans;        
    }
};
