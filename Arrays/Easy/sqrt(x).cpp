/*
Problem: Sqrt(x)
Platform: LeetCode #69
Difficulty: Easy

Approach:
1. Use the binary search algorithm to iterate through 1 to n.
2. Check at each step whether the number multiplies by itself is lesser than the required number and adjust accordingly.

Time Complexity: O(log n)
Space Complexity: O(1)

Date Solved: 2026-06-24
*/

class Solution {
public:
    int mySqrt(int x) {
        int low=1;
        int high= x;
    
        while (low<=high){
            long long mid= low+(high-low)/2;
            
            if (1LL*mid*mid==x){
                return mid;
            }

            else if (mid* mid< x){
                low=mid+1;
            }
            else {
                high= mid-1;
            }
        }
        return high;
        
    }
};
