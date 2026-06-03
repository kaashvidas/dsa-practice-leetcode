/*
Problem: Second largest and second smallest
Difficulty: Easy

Approach:
1. Initialise the largest and the smallest elements as the first element 
2. Initialise the second largest and smallest as int_min and int_max
3. Iterate through the array and compare at each step 

Time Complexity: O(n)
Space Complexity: O(n)

Date Solved: 2026-06-03
*/



#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int second_largest(vector <int> nums){
    int largest= nums[0];
    int second= -1;
    for (int i=1; i<nums.size(); i++){
        if (nums[i]>largest){
            second= largest;
            largest= nums[i];
        }
        else if (nums[i]<largest && nums[i]> second){
            second= nums[i];
        }
    }
    return second;
}

int second_smallest(vector <int> &nums){
    int smallest= nums[0];
    int second= INT_MAX;
    for (int i=1; i<nums.size(); i++){
        if (nums[i]<smallest){
            second= smallest;
            smallest= nums[i];
        }
        else if (nums[i]>smallest && nums[i]< second){
            second= nums[i];
        }
    }
    return second;
}

vector <int> f(vector <int> & nums){
    int two_largest= second_largest(nums);
    int two_smallest= second_smallest(nums);
    return {two_largest, two_smallest};
}

int main() {
    int n;
    cin>> n;
    vector <int> arr;

    for (int i=0; i<n; i++){
        int num;
        cin>> num;
        arr.push_back(num);
    }
    
    vector <int> temp= f(arr);
    for (int i=0; i<=1; i++){
        cout << temp[i]<< endl;
    }
   
    return 0;
}
