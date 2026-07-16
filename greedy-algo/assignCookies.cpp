/*
Problem: Assigning Cookies 
Platform: LeetCode #455
Difficulty: Easy

Approach:
1. Sort the greed and size arrays. 
2. Maintain two pointers to iterate through both the arrays and move the greed pointer if the corresponding size pointer is able to satisfy the greed.
3. Return the greed index at last when the size array is exhausted. 

Time Complexity: O(nlog n+ mlogm+ m)
Space Complexity: O(1)

Date Solved: 2026-07-16
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int right=0; int left=0; 
        sort(g.begin(), g.end());
        sort (s.begin(), s.end());
        while (right<g.size() && left<s.size()){
            if (g[right]<=s[left]){
                right++;
            }
            left++;
        } 
        return right;      
    }
};
