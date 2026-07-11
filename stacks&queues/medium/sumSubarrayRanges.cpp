/*
Problem: Sum of Subarray Ranges
Platform: LeetCode #2104
Difficulty: Medium 

Approach:
1. Compute the sum of subarray maximums and the sum of subarray minimums and subtract.

Time Complexity: O(n)
Space Complexity: O(n)

Date Solved: 2026-07-11
*/


class Solution {
public:
    vector <int> findNSE(vector <int> &nums){
        vector <int> nse(nums.size());
        stack <int> st;
        for (int i=nums.size()-1; i>=0; i--){
            while (!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            nse[i]=(st.empty())? nums.size(): st.top();
            st.push(i);
        }
        return nse;
    }
    vector <int> findPSEE(vector <int>&nums){
        vector <int> pse(nums.size());
        stack <int> st;
        for (int i=0; i<nums.size(); i++){
            while (!st.empty() && nums[st.top()]>= nums[i]){
                st.pop();
            }
            pse[i]= (st.empty())? -1: st.top();
            st.push(i);
        }
        return pse;
    }
    vector <int> findNGE(vector <int>&nums){
        stack <int> st;
        vector <int> nge(nums.size());
        for (int i=nums.size()-1; i>=0; i--){
            while (!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            nge[i]= (st.empty())? nums.size(): st.top();
            st.push(i);
        }
        return nge;
    }
    vector <int> findPGE(vector <int> &nums){
        stack <int> st;
        vector <int> pge(nums.size());
        for (int i=0; i<nums.size(); i++){
            while (!st.empty() && nums[st.top()]<= nums[i]){
                st.pop();
            }
            pge[i]= (st.empty())? -1: st.top();
            st.push(i);
        }
        return pge;
    }
    long long subMax(vector <int> &nums){
        long long sum=0;
        vector <int> pge= findPGE(nums);
        vector <int> nge= findNGE(nums);
        for (int i=0; i<nums.size(); i++){
            int left= nge[i]- i;
            int right= i- pge[i];
            long long contri= 1LL* right* left* nums[i];
            sum+=contri;
        }
        return sum;

    }
    long long subMin(vector <int> &nums){
        long long sum=0;
        vector <int>pse= findPSEE(nums);
        vector <int> nse= findNSE(nums);
        for (int i=0; i<nums.size(); i++){
            int right= nse[i]-i;
            int left= i-pse[i];
            long long contri= 1LL* right* left* nums[i];
            sum+=contri;
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        return subMax(nums)- subMin(nums);        
    }
};
