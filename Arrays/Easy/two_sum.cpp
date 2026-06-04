/*
Problem: Two Sum
Platform: LeetCode #1
Difficulty: Easy

Approach:
1.Store the elements and their original indices using pairs 
2. Sort the array using quick sort
3. Perform binary search to find the complement and return original indices 

Time Complexity: O(n log n)
Space Complexity: O(n)

Date Solved: 2026-06-04
*/

class Solution {
public:
int binarySearch(vector<pair<int,int>> &nums, int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid].first == target) {
            return mid;
        }
        else if (nums[mid].first < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int partition(vector<pair<int,int>> &nums, int low, int high) {

    int pivot = nums[low].first;

    int i = low;
    int j = high;

    while (i < j) {

        while (nums[i].first <= pivot && i < high) {
            i++;
        }

        while (nums[j].first > pivot && j > low) {
            j--;
        }

        if (i < j) {
            swap(nums[i], nums[j]);
        }
    }

    swap(nums[low], nums[j]);

    return j;
}

void quick_sort(vector<pair<int,int>> &nums, int low, int high) {

    if (low < high) {

        int p_index = partition(nums, low, high);

        quick_sort(nums, low, p_index - 1);

        quick_sort(nums, p_index + 1, high);
    }
}

vector<int> twoSum(vector<int> &arr, int target) {

    vector<pair<int,int>> nums;

    for (int i = 0; i < arr.size(); i++) {
        nums.push_back({arr[i], i});
    }

    quick_sort(nums, 0, nums.size() - 1);

    for (int i = 0; i < nums.size(); i++) {

        int needed = target - nums[i].first;

        int index = binarySearch(nums, nums.size(), needed);

        if (index != -1 && index != i) {

            return {
                nums[i].second,
                nums[index].second
            };
        }
    }

    return {-1, -1};
}


};
