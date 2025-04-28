// Problem 3527: Find the Most Common Response
// https://leetcode.com/problems/find-the-most-common-response/

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string, int> counter;
        
        // 跑迴圈看每日的 response
        for (const auto& response : responses) {
            // 將每日 response 去除重複後，跑迴圈加入 counter
            unordered_set<string> uniqueResponses(response.begin(), response.end());
            for (const auto& uniRes : uniqueResponses) {
                counter[uniRes]++;
            }
        }
        
        int maxFreq = 0;
        string result;
        
        // 跑迴圈比較頻率最高的以及排序最小的為答案
        for (const auto& [res, freq] : counter) {
            if (freq > maxFreq || (freq == maxFreq && res < result)) {
                maxFreq = freq;
                result = res;
            }
        }
        
        return result;
    }
};
