/*
Problem: Sum of Subarray Minimums 
Platform: LeetCode #907 
Difficulty: Medium 

Approach:
1. Use the find next smaller element and previous smaller element algos for each element of the array.
2. The number of subarrays where an element will contribute as the minimum will be given by (i-pse[i])*(nse[i]-i).

Time Complexity: O(5n)
Space Complexity: O(5n)

Date Solved: 2026-07-11
*/


class Solution {
public:
    vector <int> findNSE(vector <int>& arr){
        stack <int> st;
        vector <int> nse(arr.size());
        for (int i=arr.size()-1; i>=0; i--){
            while (!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nse[i]=(st.empty())? arr.size(): st.top();
            st.push(i);
        }
        return nse;
    }
    vector <int> findPSEE(vector <int> &arr){
        stack <int> st;
        vector <int> pse (arr.size());
        for (int i=0; i<arr.size(); i++){
            while (!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            pse[i]= (st.empty())? -1: st.top();
            st.push(i);
        }
        return pse;
    }
    long long sumSubarrayMins(vector<int>& arr) {
        int mod= 1000000007;
        vector <int> pse= findPSEE(arr);
        vector <int> nse= findNSE(arr);
        long long sum=0;
        for (int i=0; i<arr.size(); i++){
            int left= i- pse[i];
            int right= nse[i]-i;
            long long contri= 1LL* right* left* arr[i];
            sum = (sum+ contri)% mod;
        }
        return sum;        
    }
};
