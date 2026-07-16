/*
Problem: Subarray with k distinct integers 
Platform: LeetCode #992
Difficulty: Hard 

Approach:
1. Maintain two pointers- left and right and a hashmap.
2. Add the right element to the hashmap and while the mapp size is less than k, add to the count of the subarrays possible. 
3. If map size exceeds k, shorten the window by incrementing left and removing it from the map.

Time Complexity: O(n)
Space Complexity: O(n)

Date Solved: 2026-07-16
*/


class Solution {
public:
    int atMostK(vector <int> &nums, int k){
               int left=0; int right=0; int count=0;
        map <int, int> mpp;
        while (right<nums.size()){
            mpp[nums[right]]++;
            while (mpp.size()>k){
                mpp[nums[left]]--;
                if (mpp[nums[left]]==0){
                    mpp.erase(nums[left]);
                }
                left++;
            }
            count+= right-left+1;
            right++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k)- atMostK(nums, k-1);        
    }
};
