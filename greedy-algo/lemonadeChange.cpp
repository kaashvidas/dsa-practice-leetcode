/*
Problem: Lemonade Change
Platform: LeetCode #860
Difficulty: Easy

Approach:
1. Iterate through the bills array and maintain a track of five, ten and twenty dollar bills.


Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 2026-07-16
*/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0; int ten=0; int twenty=0;
        for (int i=0; i<bills.size(); i++){
            if (bills[i]==5){
                five++;
            }
            else if(bills[i]==10){
                if (five){
                    five--;
                    ten++;
                }
                else {
                    return false;
                }
            }
            else {
                if (five && ten){
                    five--;
                    ten--;
                    twenty++;
                }
                else if (five>=3){
                    five= five-3;
                    twenty++;
                }
                else {
                    return false;
                }
            }
        }
        return true;
        
    }
};
