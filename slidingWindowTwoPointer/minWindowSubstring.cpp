/*
Problem: Minimum Window Substring
Platform: LeetCode #76
Difficulty: Hard 

Approach:
1. Maintain two pointers-right and left. 
2. Store the charcaters in the string t along with their frequencies in the hashmap beforehand.
3. While iterating through the string s, decrease the hash value for each right character and if it was positive previously, increment count.
4. If count equals the length of string t, try to minimise the window by incrementing left pointer and increasing its hash value and adjusting count accordingly.

Time Complexity: O(n)
Space Complexity: O(256)

Date Solved: 2026-07-16
*/


class Solution {
public:
    string minWindow(string s, string t) {
        int right=0; int left=0;
        int minLen= INT_MAX;
        int start=-1;
        int count=0;
        vector <int> hash (256, 0);
        for (int i=0; i<t.size(); i++){
            hash[t[i]]++;
        }
        while(right<s.size()){
            if (hash[s[right]]>0){
                count++;
            }
            hash[s[right]]--;
            while(count==t.size()){
                if (right-left+1<minLen){
                    minLen= right-left+1;
                    start=left;
                }
                hash[s[left]]++;
                if (hash[s[left]]>0){
                    count--;
                }
                left++;
            } 
            right++;
        }
        return start==-1? "": s.substr(start, minLen);
        
    }
};
