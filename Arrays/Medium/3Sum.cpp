/*
Problem: Three Sum 
Platform: LeetCode #1
Difficulty: Medium

Approach:
1. Sort the array
2. Use the two pointer approach
3. Keep in mind to avoid duplicates 

Time Complexity: O(n^2)
Space Complexity: O(n)

Date Solved: 2026-06-10
*/



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector <vector <int>> v;
        sort(nums.begin(), nums.end());

        for (int i=0; i<nums.size(); i++){
            
            if (i>0 && nums[i]== nums[i-1]){
                continue;
            }

            int j= i+1;
            int k= nums.size()-1;

            while (j<k){
                int sum= nums[i]+ nums[j] + nums[k];
                 
                if (sum<0){
                    j++;
                }

                else if (sum>0){
                    k--;
                }

                else {
                    v.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while (j<k && nums[j]==nums[j-1]){
                        j++;
                    }

                    while (j<k && nums[k]==nums[k+1]){
                        k--;
                    }
                }
            }

        }
        return v;
           
    }
};
