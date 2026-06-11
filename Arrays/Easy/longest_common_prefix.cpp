/*
Problem: Longest Common Prefix 
Platform: LeetCode #1
Difficulty: Easy

Approach:
1. Start with the first string as the prefix 
2. Shorten the prefix if it does not match with the subsequent strings in the array

Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 2026-06-11
*/


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string prefix= strs[0];

        for (int i=1; i<strs.size(); i++){
            while (strs[i].find(prefix)!=0){
                prefix.pop_back();
            }
            if (prefix.empty()){
                return "";
            }
        }
        return prefix;

        
    }
};
