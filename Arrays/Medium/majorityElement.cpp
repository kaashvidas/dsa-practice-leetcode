/*
Problem: Majority Element 
Platform: LeetCode #1
Difficulty: Medium 

Approach:
1. Use Bpyer-Moore's Voting Algorithm to iterate through the array once 
2. Take the first element as te reference, if the other elements match it, increment the counter else decrement it.
3. Reset the reference element every time the counter equals zero, because that indicates the elements has been cancelled out by other elements and isnt the
majority element in that part of the array.

Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 2026-06-13
*/



#include <bits/stdc++.h>

int majorityElement(vector <int> &nums){
    int count=0; 
    int el=0;
    
    for (int i=0; i<nums.size(); i++){
        if (count==0){
            el= nums[i];
            count++;
        }
        
        else if (nums[i]==el){
            count++;
        }
        
        else {
            count--;
        }
    
    }
    return el;
}

int main() {
    int n;
    cin>> n;
    vector <int> array;
    for (int i=0; i<n; i++){
        int num;
        cin>> num;
        array.push_back(num);
    }
    
    cout<< majorityElement(array);
    
    return 0;
}
