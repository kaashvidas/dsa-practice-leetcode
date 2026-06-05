/*
Problem: Waviness of a range of numbers II
Platform: LeetCode #1
Difficulty: Hard

Approach:
1. Using Digit Dynamic Programming

Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 2026-06-05
*/




class Solution {
public:

    struct Node {
        long long ways;
        long long waviness;
    };

    Node dp[20][11][11][2][2];
    bool vis[20][11][11][2][2];

    string s;

    Node solve(int pos,
               int prev1,
               int prev2,
               int tight,
               int started) {

        if (pos == s.size()) {
            return {1, 0};
        }

        if (vis[pos][prev1][prev2][tight][started]) {
            return dp[pos][prev1][prev2][tight][started];
        }

        vis[pos][prev1][prev2][tight][started] = true;

        Node ans = {0, 0};

        int limit =
            tight ? s[pos] - '0' : 9;

        for (int d = 0; d <= limit; d++) {

            int newTight =
                tight && (d == limit);

            // leading zeros
            if (!started && d == 0) {

                Node nxt =
                    solve(pos + 1,
                          10,
                          10,
                          newTight,
                          0);

                ans.ways += nxt.ways;
                ans.waviness += nxt.waviness;
            }

            // first digit
            else if (!started) {

                Node nxt =
                    solve(pos + 1,
                          d,
                          10,
                          newTight,
                          1);

                ans.ways += nxt.ways;
                ans.waviness += nxt.waviness;
            }

            else {

                long long add = 0;

                if (prev2 != 10) {

                    bool valley =
                        (prev1 < prev2 &&
                         prev1 < d);

                    bool peak =
                        (prev1 > prev2 &&
                         prev1 > d);

                    if (valley || peak) {
                        add = 1;
                    }
                }

                Node nxt =
                    solve(pos + 1,
                          d,
                          prev1,
                          newTight,
                          1);

                ans.ways += nxt.ways;

                ans.waviness +=
                    nxt.waviness +
                    add * nxt.ways;
            }
        }

        return dp[pos][prev1][prev2][tight][started]
               = ans;
    }

    long long countWaviness(long long num) {

        s = to_string(num);

        memset(vis, false, sizeof(vis));

        return solve(0, 10, 10, 1, 0).waviness;
    }

    long long totalWaviness(long long num1,
                            long long num2) {

        return countWaviness(num2)
             - countWaviness(num1 - 1);
    }
};
