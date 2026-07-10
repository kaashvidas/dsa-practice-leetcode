/*
Problem: Trapping Rainwater
Platform: LeetCode #42
Difficulty: Hard 

Approach:
1. Maintain two pointers- left and right along with leftmax and rightmax.
2. Always traverse through the smaller values first.
3. If the left value is smaller than both the right value and leftmax, update the water storage and similarly for the right value.

Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 2026-07-10
*/


class Solution {
public:
    int trap(vector<int>& height) {
        int l=0; int r=height.size()-1;
        int lmax=0;
        int rmax=0; 
        int total=0;
        while (l<r){
            if (height[l]<height[r]){
                if (height[l]<lmax){
                    total+=lmax-height[l];
                }
                else {
                    lmax=height[l];
                }
                l++;
            }
            else {
                if (height[r]<rmax){
                    total+=rmax-height[r];
                }
                else {
                    rmax=height[r];
                }
                r--;
            }
        }
        return total;
    }
};
