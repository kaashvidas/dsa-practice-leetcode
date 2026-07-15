/*
Problem: Longest Repeating Character
Platform: LeetCode #424
Difficulty: Medium 

Approach:
1. Maintain two pointers- right and left. 
2. Store the frequency of the right character in the hashmap, and at each step, update the max frequency.
3. If the window exceeds k replacements, shorten the window by incremeneting left pointer and resetting maxFreq to 0.

Time Complexity: O(n)
Space Complexity: O(26)

Date Solved: 2026-07-15
*/


class Solution {
public:
    int characterReplacement(string s, int k) {
        int right=0; 
        int left=0;
        int maxLen=0;
        int maxFreq=0;
        vector <int> hash(26, 0);
        while (right<s.size()){
            hash[s[right]-'A']++;
            maxFreq= max(maxFreq, hash[s[right]-'A']);
            if ((right-left+1)- maxFreq>k)  {
                hash[s[left]-'A']--;
                maxFreq=0;
                left++;
            } 
            if ((right-left+1)-maxFreq<=k){
                maxLen= max(maxLen, right-left+1);
            } 
            right++;        
        }
        return maxLen;
        
    }
};
