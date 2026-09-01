/*
Problem: Beauty Sum of substrings
Platform: LeetCode #1781
Difficulty: Medium

Approach:
1. Generate all the substrings of the string and maintain an unordered hashmap to store the frequencies of the characters.
2. At each step, add the difference of the max and min frequencies. 

Time Complexity: O(n^2)
Space Complexity: O(26)

Date Solved: 2026-09-01
*/


class Solution {
public:
    int beautySum(string s) {

        int sum = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {

            int freq[26] = {0};

            for (int j = i; j < n; j++) {

                freq[s[j] - 'a']++;

                int maxi = 0;
                int mini = INT_MAX;

                for (int k = 0; k < 26; k++) {

                    if (freq[k] > 0) {
                        maxi = max(maxi, freq[k]);
                        mini = min(mini, freq[k]);
                    }
                }

                sum += maxi - mini;
            }
        }

        return sum;
    }
};
