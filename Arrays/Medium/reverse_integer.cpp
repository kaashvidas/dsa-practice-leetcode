/*
Problem: Reverse Integer 
Platform: LeetCode #1
Difficulty: Medium

Approach:
1. Extract the digits and store in reverse order 
2. If reversing the digit exceeds the 32 bit integer, return 0


Time Complexity: O(d) (No of digits in the number)
Space Complexity: O(1)

Date Solved: 2026-06-04
*/




    class Solution {
public:
    int reverse(int x) {

        int rev = 0;

        while (x != 0) {

            int rem = x % 10;
            x = x / 10;
          
            if (rev > INT_MAX / 10 ||
               (rev == INT_MAX / 10 && rem > 7)) {
                return 0;
            }
          
            if (rev < INT_MIN / 10 ||
               (rev == INT_MIN / 10 && rem < -8)) {
                return 0;
            }

            rev = rev * 10 + rem;
        }

        return rev;
    }
};
