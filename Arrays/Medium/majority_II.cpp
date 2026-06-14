/*
Problem: Majority Element II
Platform: LeetCode #1
Difficulty: Medium 

Approach:
1. Store the elements in an unordered hashmap.
2. If the element occurs more than n/3, it is pushed into the answer vector.

Time Complexity: O(N)
Space Complexity: O(2n)

Date Solved: 2026-06-14
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n= nums.size();
        int times= (n/3);
        vector <int> ans;
        unordered_map <int, int> mpp;
        for (int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }

        for (auto it: mpp){
            if (it.second> times){
                ans.push_back(it.first);
            }
        }

        return ans;

        
    }
};
