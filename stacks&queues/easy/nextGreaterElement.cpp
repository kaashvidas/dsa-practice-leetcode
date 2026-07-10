/*
Problem: Next Greater Element 
Platform: LeetCode #496
Difficulty: Easy

Approach:
1. Use the montonic decreasing stack for iterating through nums2 and storing the nge for each element.
2. Store the element and its nge in a hashmap.
3. Iterate through nums1 and return its nge from the hashmap.

Time Complexity: O(n+m)
Space Complexity: O(n)+ O(m)

Date Solved: 2026-07-10
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map <int, int> mpp;
        stack <int> st;
        for (int i= nums2.size()-1; i>=0; i--){
            while (!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if (st.empty()){
                mpp[nums2[i]]=-1;
            }
            else {
                mpp[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }

        vector <int> nums;
        for (int i=0; i<nums1.size(); i++){
            nums.push_back(mpp[nums1[i]]);
        }
        return nums;
        
    }
};
