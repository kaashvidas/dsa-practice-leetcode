/*
Problem: Three Sum- closest
Platform: LeetCode #1
Difficulty: Medium

Approach:
1. Sort the array
2. Use two pointer approach
3. Compare the sum with the closest at each step

Time Complexity: O(n^2)
Space Complexity: O(1)

Date Solved: 2026-06-10
*/



class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
         sort(nums.begin(), nums.end());
         long long closest=INT_MAX;

        for (int i=0; i<nums.size(); i++){
            

            int j= i+1;
            int k= nums.size()-1;

            while (j<k){
                long long sum= nums[i]+ nums[j] + nums[k];
                 
                if (sum<target){
                    if (abs(sum-target)<abs(closest-target)){
                        closest=sum;
                    }
                    j++;
                }

                else if (sum>target){
                     if (abs(sum-target)<abs(closest-target)){
                        closest=sum;
                    }
                    k--;
                }

                else {
                
                    return (int)sum;;
                }
            }

        }
        return (int)closest;
        
    }
};
