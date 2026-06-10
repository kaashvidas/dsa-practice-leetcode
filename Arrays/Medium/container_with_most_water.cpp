/*
Problem: Container with most water
Platform: LeetCode #1
Difficulty: Medium

Approach:
1. The amouunt of water stored is the area 
2. Use two pointer approach and shift the pointer with the smaller height 

Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 2026-06-11
*/



class Solution {
public:
    int maxArea(vector<int>& height) {
        int areaMax=0;
        int left=0;
        int right= height.size()-1;
        while (left<right){
           int  length= min(height[left], height[right]);
            int width= right-left;
            int area= length*width;
            areaMax= max(areaMax, area);
            if (height[left]<height[right]){
                left++;
            }     
            else {
                right--;
            }  
        }

            return areaMax;
    }
};
