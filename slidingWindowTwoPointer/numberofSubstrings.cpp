/*
Problem: Number of Substrings with atleast one of each 
Platform: LeetCode #1358
Difficulty: Medium 

Approach:
1. SIterate through the array and update the last indexes of all the three characters.
2. Take the minimum window seen till then conataining all three characters and add all previous places to it.

Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 2026-07-16
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int count=0;
        vector <int> lastSeen(3, -1);
        for (int i=0; i<s.size(); i++){
            lastSeen[s[i]-'a']= i;
            count+= 1+ min(lastSeen[0], min (lastSeen[1], lastSeen[2]));
        }
        return count; 
    }
};
