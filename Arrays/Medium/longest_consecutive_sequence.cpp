/*
Problem: Longest Consecutive Sequence 
Platform: LeetCode #1
Difficulty: Medium 

Approach:
1. Brute Force- Iterate through the array and for every element, if the next element is found in the array, increment the counter and compare with longest.
2. Better Solution- Sort the array and maintain the last smaller element, longest and count pointer. 
3. Optimal Solution- Put the elements into an unordered set, for every element in the set check if the previous element is present in the set, if yes, skip it. 
Find an element wose previous element is not present in the set. Check if the consecutive elements are present in the set and update count and longest. (This is 
the optimal solution since we iterate through the array once and store it in an unordered set, thereon for favourable conditions, the time taken to find an element
in the set is O(1))

Time Complexity: O(n)
Space Complexity: O(n)

Date Solved: 2026-06-13
*/



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> st;
        int longest=0;
        int n= nums.size();
        for (int i=0; i<n; i++){
            st.insert(nums[i]);
        }

        for (auto it: st){
            if (st.find(it-1)==st.end()){
                int count=1;
                int x= it;
                while (st.find(x+1)!=st.end()){
                    x=x+1;
                    count++;
                }
                longest=max(longest, count);
            }
        }
        return longest;
        
    }
};
