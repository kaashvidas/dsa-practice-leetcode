/*
Problem: Remove k digits 
Platform: LeetCode #402 
Difficulty: Medium 

Approach:
1. Iterate from the beginning of the string and maintain a stack alongside.
2. If the incoming number is smaller than the top of the stack and you still have digits to remove, pop the top of the stack.
3. If the number is greater than top, push it. 
4. deal with edge cases like trimming zeroes, k=n, etc.

Time Complexity: O(n)
Space Complexity: O(n)

Date Solved: 2026-07-11
*/


class Solution {
public:
    string removeKdigits(string num, int k) {
        stack <char> st;
        for (int i=0; i<num.size(); i++){
            while (!st.empty() && k>0 && num[i]-'0'<st.top()-'0'){
                    st.pop();
                    k--;
            }
            st.push(num[i]);
        }
        while (k>0){
            st.pop();
            k--;
        }
        if (st.empty()){
            return "0";
        }
        string res="";
        while (!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        while (res.size() && res.back()=='0'){
            res.pop_back();
        }
        if (res.empty()){
            return "0";
        }
    
    reverse(res.begin(), res.end());
    return res;
        
        
    }
};
