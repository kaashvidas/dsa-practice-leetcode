/*
Problem: Longest Substring without Repeating Characters
Platform: LeetCode #3
Difficulty: Medium 

Approach:
1. Maintain two pointers- l and r. 
2. While the right pointer does not excedd the length of the string, maintain a hash map and store the last occurence of each character.
3. While the character does not repeat, add to the length of the substring.

Time Complexity: O(n)
Space Complexity: O(256)

Date Solved: 2026-07-14
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi = 0;
        int l = 0, r = 0;

        vector<int> hash(256, -1);

        while (r < s.size()) {
            if (hash[s[r]] != -1 && hash[s[r]] >= l) {
                l = hash[s[r]] + 1;
            }

            maxi = max(maxi, r - l + 1);
            hash[s[r]] = r;
            r++;
        }

        return maxi;
    }
};
