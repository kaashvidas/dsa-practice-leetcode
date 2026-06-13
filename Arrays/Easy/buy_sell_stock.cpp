/*
Problem: Best Time to Buy and Sell Stock
Platform: LeetCode #1
Difficulty: Easy

Approach:
1. For selling the stock on the ith day, the stock needs to be bought from the 1st to (i-1)th day
2. Iterate through the array and maintain the day on which the price was minimum 
3. Compare the cost at each step and update the profit accordingly 

Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 2026-06-13
*/



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int mini= prices[0];

        for (int i=1; i<prices.size(); i++){
            int cost= prices[i]-mini;
            profit= max(profit, cost);
            mini= min(mini, prices[i]);
        }
        return profit;
        
    }
};
