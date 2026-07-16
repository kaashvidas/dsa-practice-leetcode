/*
Problem: Valid Parentheses String 
Platform: LeetCode #678
Difficulty: Medium 

Approach:
1. Maintain min and max- the range between which the ans can lie.
2. Increment both when opening parentheses is encountered, decrement for closing.
3. For an asterisk, decrement min and increment max. At any step if max is negative, return false.

Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 2026-07-16
*/

class Solution {
public:
    bool checkValidString(string s) {
        int min=0; int max=0;
        for (int i=0; i<s.size(); i++){
            if (s[i]=='('){
                min++;
                max++;
            }
            else if (s[i]==')'){
                min--;
                max--;
            }
            else {
                min--;
                max++;
            }
            if (min<0){
                min=0;
            }
            if (max<0){
                return false;
            }
        }
        return (min==0);        
    }
};
