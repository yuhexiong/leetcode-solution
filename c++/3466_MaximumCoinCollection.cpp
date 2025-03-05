// Problem 3466: Maximum Coin Collection
// https://leetcode.com/problems/maximum-coin-collection/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    // 比大小的 function
    long long max(long long a, long long b) {
        return (a > b) ? a : b;
    }

    long long maxCoins(vector<int>& lane1, vector<int>& lane2) {
        int n = lane1.size();
        
        // dp[i][0]：不切換車道的最大硬幣數（只在 lane1）
        // dp[i][1]：第 i 英里，最多切換一次車道的最大硬幣數（從 lane1 到 lane2）
        // dp[i][2]：第 i 英里，最多切換兩次車道的最大硬幣數（最後在 lane1）
        vector<vector<long long>> dp(n, vector<long long>(3, INT_MIN));

        // 初始化第 0 英里
        dp[0][0] = lane1[0];      // 從車道 1 進入
        dp[0][1] = lane2[0];      // 最一開始就切入車道 2
        dp[0][2] = INT_MIN;       // 不可能在第 0 英里切換兩次車道
        // 提早離開車道
        long long exits = max(lane1[0], lane2[0]);

        for (int i = 1; i < n; ++i) {
            // 不切換車道，繼續在同一車道行駛 或 從這個入口進來
            dp[i][0] = max(dp[i - 1][0] + lane1[i], 0 + lane1[i]);

            // 從車道 1 切換到車道 2 或 繼續在車道 2 或 從這個入口進來
            dp[i][1] = max(max(dp[i - 1][0] + lane2[i], dp[i - 1][1] + lane2[i]), 0 + lane2[i]);

            // 已經切回車道 1 後繼續在車道 1，或從車道 2 切換回車道 1
            dp[i][2] = max(dp[i - 1][2] + lane1[i], dp[i - 1][1] + lane1[i]);

            // 提早離開
            exits = max(exits, dp[i][0]);
            exits = max(exits, dp[i][1]);
            exits = max(exits, dp[i][2]);
        }

        // 最終結果，最大硬幣數是在最多切換兩次車道的情況下獲得的
        return max(max(dp[n - 1][0], dp[n - 1][1]), max(dp[n - 1][2], exits));
    }
};