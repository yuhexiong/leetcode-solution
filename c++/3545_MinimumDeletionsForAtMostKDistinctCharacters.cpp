// Problem 3545: Minimum Deletions for At Most K Distinct Characters
// https://leetcode.com/problems/minimum-deletions-for-at-most-k-distinct-characters/

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char, int> cnt;

        // 計算每個字母出現的次數
        for (char ch : s) {
            cnt[ch]++;
        }

        // 將字母和次數轉成 vector 並從大排到小
        vector<pair<char, int>> sorted_cnt(cnt.begin(), cnt.end());
        sort(sorted_cnt.begin(), sorted_cnt.end(), [](const auto &a, const auto &b) {
            return a.second > b.second;
        });

        // 計算需要刪除的總數，k 以後的都要刪除
        int deletionCnt = 0;
        for (size_t i = k; i < sorted_cnt.size(); i++) {
            deletionCnt += sorted_cnt[i].second;
        }

        return deletionCnt;
    }
};