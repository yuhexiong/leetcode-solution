// Problem 3528: Unit Conversion I
// https://leetcode.com/problems/unit-conversion-i/description/

#include <functional>
#include <list>
#include <vector>
using namespace std;

class Solution {
    public:
    static const int MOD = 1e9 + 7;

    vector<int> baseUnitConversions(vector<vector<int>> &conversions) {
        int n = conversions.size();
        // 設定答案，預設沒資料都是 -1
        vector<int> baseUnitConv(n + 1, -1);
        // 第 0 筆資料為 1 分 "第 0 筆資料單位"
        baseUnitConv[0] = 1;

        // 整理反向 map
        unordered_map<int, list<pair<int, int>>> reverseMap;
        for (const auto &conversion : conversions) {
            int source = conversion[0], target = conversion[1],
                factor = conversion[2];
            reverseMap[target].emplace_back(source, factor);
        }

        // 設定 dfs function
        function<void(int, int, int)> processSourceConv =
            [&](int source, int target, int factor) {
                if (baseUnitConv[source] == -1) {
                    // 假如 source 還沒設定，使用 reverseMap 往前設定
                    for (const auto &prev : reverseMap[source]) {
                        // 前一個節點使用 processSourceConv 尋找並設定
                        processSourceConv(prev.first, source, prev.second);
                        // 直到 source 確定設定完畢
                        if (baseUnitConv[source] != -1) {
                            break;
                        }
                    }
                }

                // 目標單位設定成 來源乘以倍數
                long long conv = baseUnitConv[source] % MOD;
                conv = (conv * factor % MOD) % MOD;
                baseUnitConv[target] = static_cast<int>(conv);
            };

        // 跑迴圈處理每個 conversion
        for (const auto &conversion : conversions) {
            int source = conversion[0], target = conversion[1],
                factor = conversion[2];
            processSourceConv(source, target, factor);
        }

        // 回傳答案
        return baseUnitConv;
    }
};