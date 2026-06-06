/*
Problem: Left and Right Sum 
Platform: LeetCode #1
Difficulty: Easy

Approach:
1. Define left and right sum arrays 4
2. Iterate through the nums array and store the left and right sum simultaneously 
3. Define and calculate the answers array

Time Complexity: O(n)
Space Complexity: O(3n)

Date Solved: 2026-06-06
*/



class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector <int> answer;
        int n= nums.size();
        int leftSum[n];
        int rightSum[n];
        leftSum[0]=0;
        rightSum[n-1]=0;
        for (int i=1; i<n; i++){
            leftSum[i]= leftSum[i-1]+nums[i-1];
        }
        for (int i=n-2; i>=0; i--){
            rightSum[i]= rightSum[i+1]+nums[i+1];
        }
        for (int i=0; i<n; i++){
            answer.push_back(abs(leftSum[i]- rightSum[i]));
        }
        return answer;
    }
};
