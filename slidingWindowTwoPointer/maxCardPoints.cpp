/*
Problem: Maximum Card Points 
Platform: LeetCode #1423
Difficulty: Medium 

Approach:
1. Calculate the sum of the k leftmost elements first and initialise that as the leftsum. 
2. Next, at each step shorten the left window and add one element to the right window and calculate the left and right sum to get the total score.
3. Update max score at each step.

Time Complexity: O(2k)
Space Complexity: O(1)

Date Solved: 2026-07-16
*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum=0; int rightSum=0; int maxSum=0;
        for (int i=0; i<k; i++){
            leftSum+= cardPoints[i];
        }
        maxSum=leftSum;
        int right=cardPoints.size()-1;
        for (int i= k-1; i>=0; i--){
            leftSum-=cardPoints[i];
            rightSum+=cardPoints[right];
            right--;
            maxSum= max(leftSum+rightSum, maxSum);
        }
        return maxSum;        
    }
};
