/*
Problem: Reverse Pairs 
Platform: LeetCode #493
Difficulty: Hard

Approach:
1. Use the merge sort algorithm.
2. Make a function countPairs to iterate through the elements in the left array and for every element that forms a pair, increment the right pointer and increment
count by the number of elements before the pointer in the right array.
3. Include countPairs in the merge sort function to return count.

Time Complexity: O(n log n)
Space Complexity: O(n)

Date Solved: 2026-06-17
*/



class Solution {
public:
    void merge(vector <int> &nums, int low, int mid, int high){
        vector <int> temp;
        int left=low;
        int right= mid+1;
        while (left<=mid && right<=high){
            if (nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while (left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while (right<=high){
            temp.push_back(nums[right]);
            right++;
        }
        for (int i=low; i<=high; i++){
            nums[i]= temp[i-low];
        }
    }

    long long countPairs(vector <int> &nums, int low, int mid, int high){
        long long cnt=0;
        int right= mid+1;
        for (int i=low; i<=mid; i++){
            while (right<=high && nums[i]> 2LL*nums[right]){
            right++;
            }
            cnt+=right-(mid+1);
        }
        return cnt;       
    }

    long long mergeSort(vector <int> &nums, int low, int high){
        long long cnt=0;
        if (low>=high) return cnt;
        int mid= low+(high-low)/2;
        cnt+=mergeSort(nums, low, mid);
        cnt+=mergeSort(nums, mid+1, high);
        cnt+=countPairs(nums, low, mid, high);
        merge(nums, low, mid, high);
        return cnt;
    }

    long long reversePairs(vector<int>& nums) {
        long long cnt=0;
        cnt= mergeSort(nums, 0, nums.size()-1);
        return cnt;        
    }
};
