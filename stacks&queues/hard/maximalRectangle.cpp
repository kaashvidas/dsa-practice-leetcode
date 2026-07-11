/*
Problem: Maximal Rectangle 
Platform: LeetCode #85
Difficulty: Hard 

Approach:
1. Maintain a heights array for treating each row as a histogram.
2. Call the largest rectangle in histogram function for each row.
3. Update the maximum area accordingly.

Time Complexity: O(n*m)
Space Complexity: O(n)

Date Solved: 2026-07-11 
*/


class Solution {
public:
    int largestRectangle(vector<int>&nums){
        stack <int> st;
        int maxArea=0;
        for (int i=0; i<nums.size(); i++){
            while (!st.empty() && nums[st.top()]> nums[i]){
                int element= nums[st.top()];
                st.pop();
                int pse= st.empty()? -1: st.top();
                int nse= i;
                int area= element* (nse-pse-1);
                maxArea= max(maxArea, area);
            }
            st.push(i);
        }
        while (!st.empty()){
            int element= nums[st.top()];
            st.pop();
            int pse= st.empty()? -1: st.top();
            int nse= nums.size();
            int area= element* (nse-pse-1);
            maxArea= max(maxArea, area);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector <int> heights(matrix[0].size());
        int maxArea=0;
        for (int i=0; i<matrix.size(); i++){
            for (int j=0; j<matrix[0].size(); j++){
                if (matrix[i][j]=='1'){
                    heights[j]++;
                }
                else {
                    heights[j]=0;
                }
            }
            int area= largestRectangle(heights);
            maxArea= max(area, maxArea);
        }
        return maxArea;        
    }
};
