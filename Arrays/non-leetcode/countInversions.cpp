/*
Problem: Count the Inversions 
Platform: Striver's DSA Playlist
Difficulty: Hard 

Approach:
1. In the merge sort algorithm, while checking for the left and right element, add the condition that if the right element is smaller, increment the count of
inversions by the number of elements on the right of left pointer in the left array.

Time Complexity: O(n log n)
Space Complexity: O(n)

Date Solved: 2026-06-17
*/




class Solution {
public:

   int merge(vector<int>&nums, int low, int mid, int high){
    vector <int> temp;
    int cnt=0;
    int left= low;
    int right= mid+1;
    while (left<=mid && right<=high){
        if (nums[left]<=nums[right]){
            temp.push_back(nums[left]);
            left++;
        }
        else {
            temp.push_back(nums[right]);
            cnt+=(mid-left+1);
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
        nums[i]=temp[i-low];
    }
    return cnt;
   }


int mergeSort(vector <int> &nums, int low, int high){
  
    int cnt=0;
    if (low>=high) return cnt;
      int mid= (low+high)/2;
    cnt+=mergeSort(nums, low, mid);
    cnt+=mergeSort(nums, mid+1, high);
    cnt+=merge(nums, low, mid, high);
    return cnt;

}
   long long int numberOfInversions(vector<int> nums) {
    long long int count=0;
    count= mergeSort(nums, 0, nums.size()-1);
    return count;

    }
};
