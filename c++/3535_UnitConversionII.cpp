// Problem 3535: Unit Conversion II
// https://leetcode.com/problems/unit-conversion-ii/

#include <vector>
#include <functional>
#include <list>
using namespace std;

class Solution
{
public:
    static const int MOD = 1e9 + 7;
    vector<int> queryConversions(vector<vector<int>> &conversions, vector<vector<int>> &queries)
    {
        int n = conversions.size();
        // 設定答案，預設沒資料都是 -1
        vector<int> baseUnitConv(n + 1, -1);
        // 第 0 筆資料為 1 分 "第 0 筆資料單位"
        baseUnitConv[0] = 1;

        // 整理反向 map
        unordered_map<int, list<pair<int, int>>> reverseMap;
        for (const auto &conversion : conversions)
        {
            int source = conversion[0], target = conversion[1], factor = conversion[2];
            reverseMap[target].emplace_back(source, factor);
        }

        // 設定 dfs function
        function<void(int, int, int)> dfs = [&](int source, int target, int factor)
        {
            if (baseUnitConv[source] == -1)
            {
                // 假如 source 還沒設定，使用 reverseMap 往前設定
                for (const auto &prev : reverseMap[source])
                {
                    // 前一個節點使用 dfs 尋找並設定
                    dfs(prev.first, source, prev.second);
                    // 直到 source 確定設定完畢
                    if (baseUnitConv[source] != -1)
                    {
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
        for (const auto &conversion : conversions)
        {
            int source = conversion[0], target = conversion[1], factor = conversion[2];
            dfs(source, target, factor);
        }

        // 前面段與 Unit Conversion I 相同
        // 跑迴圈依題意比較每組 a, b 的值並加入 queryConv
        vector<int> queryConv;
        for (const auto &query : queries)
        {
            int unitA = query[0], unitB = query[1];
            // 使用模反元素來計算轉換結果
            long long conv = baseUnitConv[unitB];
            conv = (conv * modInverse(baseUnitConv[unitA])) % MOD;
            queryConv.push_back(static_cast<int>(conv % MOD));
        }

        // 回傳答案
        return queryConv;
    }

private:
    // 計算模反元素
    int modInverse(long num)
    {
        int result = 1;
        int exponent = MOD - 2;
        while (exponent > 0)
        {
            if (exponent % 2 == 1)
            {
                result = (result * num) % MOD;
            }
            num = (num * num) % MOD;
            exponent /= 2;
        }
        return int(result);
    }
};