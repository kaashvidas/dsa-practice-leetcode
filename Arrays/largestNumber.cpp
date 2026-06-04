/*
Problem: Largest Number 
Platform: LeetCode #1
Difficulty: Medium

Approach:
1. Compare the strings ab and ba of two consecutive number elements in the array
2. Perform bubble sort based on the comparison
3. Append the elements as the string to return the largest number possible 

Time Complexity: O(n^2)
Space Complexity: O(1)

Date Solved: 2026-06-04
*/



#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    bool compare(int a, int b) {

        string x = to_string(a);
        string y = to_string(b);

        return x + y > y + x;
    }

    string largestNumber(vector<int>& nums) {

        for (int i = 0; i < nums.size() - 1; i++) {

            for (int j = 0; j < nums.size() - i - 1; j++) {

                if (!compare(nums[j], nums[j + 1])) {

                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }


        if (nums[0] == 0) {
            return "0";
        }

        string ans = "";

        for (int i = 0; i < nums.size(); i++) {
            ans += to_string(nums[i]);
        }

        return ans;
    }
};
